#include "include\Trader.h"
#include <QDir>
#include <iostream>
using namespace std;

CTrader::CTrader(int index, Account account)
{
	cout << "CTrader init:"<< QThread::currentThreadId() <<endl;

	strcpy(m_FRONT_ADDR, account.td_front_addr);
	strcpy(m_BROKER_ID, account.broker_id);
	strcpy(m_INVESTOR_ID, account.inverst_id);
	strcpy(m_PASSWORD, account.password);
	m_iRequestID = 0;
	m_index = index;
    m_followDirect = account.direct;
    m_followRatio = account.ratio;

	sprintf(m_flowPath, "%s\\%s\\", QCoreApplication::applicationDirPath().toStdString().c_str(), m_INVESTOR_ID);
    QDir dir;
    if(!dir.exists(m_flowPath))
    {
        dir.mkdir(QString::fromLocal8Bit(m_flowPath));
    }
    m_pTraderApi = CThostFtdcTraderApi::CreateFtdcTraderApi(m_flowPath);			// 创建UserApi
    m_pTraderSpi = new CTraderSpi();
}

CTrader::~CTrader()
{
	cout << "CTrader destroy:" << QThread::currentThreadId() << endl;
    m_pTraderApi->Release();  // 一定要先始发交易api
    delete m_pTraderSpi;
}

void CTrader::SetThread(QThread * thread)
{
	m_pThread = thread;
	this->moveToThread(thread);
}

bool CTrader::IsFlowControl(int iResult)
{
	return ((iResult == -2) || (iResult == -3));
}

void CTrader::ReqConnect()
{
	cout << "user Login:"<< QThread::currentThreadId() <<endl;

	QObject::connect(m_pTraderSpi, &CTraderSpi::frontConnected, this, &CTrader::ReqUserLogin);
	QObject::connect(m_pTraderSpi, &CTraderSpi::rspUserLogin, this, &CTrader::rspUserLogin);
	QObject::connect(m_pTraderSpi, &CTraderSpi::rspSettlementInfoConfirm, this, &CTrader::ReqQryTradingAccount);
    QObject::connect(m_pTraderSpi, &CTraderSpi::rspQryTradingAccount, this, &CTrader::rspQryTradingAccount);
    QObject::connect(m_pTraderSpi, &CTraderSpi::RtnTradeEvent, this, &CTrader::ProcessTradeEvent);

	m_pTraderApi->RegisterSpi((CThostFtdcTraderSpi*)m_pTraderSpi);		// 注册事件类
	m_pTraderApi->SubscribePublicTopic(THOST_TERT_QUICK);				// 注册公有流
	m_pTraderApi->SubscribePrivateTopic(THOST_TERT_QUICK);				// 注册私有流
	m_pTraderApi->RegisterFront(m_FRONT_ADDR);							// connect
	cout << "front_addr" << m_FRONT_ADDR <<endl;
	m_pTraderApi->Init();
	// m_pTraderApi->Join();
	emit traderStatusUpdated(m_index, QString::fromLocal8Bit("已连接交易服务器"));
}

void CTrader::ReqLogout()
{
    emit traderStatusUpdated(m_index, QString::fromLocal8Bit("账户已退出"));
    emit traderBalanceUpdated(m_index, 0.0, 0.0, 0.0);
    emit eventTableUpdated(QString::fromLocal8Bit("账号%1已经退出登录").arg(m_INVESTOR_ID));
    m_pThread->quit();
}

void CTrader::ReqUserLogin()
{
	CThostFtdcReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.BrokerID, m_BROKER_ID);
	strcpy(req.UserID, m_INVESTOR_ID);
	strcpy(req.Password, m_PASSWORD);
	int iResult = m_pTraderApi->ReqUserLogin(&req, ++m_iRequestID);
	if(iResult==0)
	{
		cout << "--->>> 发送用户登录请求: 成功" << QThread::currentThreadId() << endl;
		emit traderStatusUpdated(m_index, QString::fromLocal8Bit("成功发送登录请求"));
	}
	else
	{
        cout << "--->>> 发送用户登录请求: 失败" << QThread::currentThreadId() << endl;
        emit traderStatusUpdated(m_index, QString::fromLocal8Bit("发送登录请求失败"));
	}
}

void CTrader::rspUserLogin(int front_id ,int session_id, int iNextOrderRef)
{
	m_FRONT_ID = front_id;
	m_SESSION_ID = session_id;
    m_iNextOrderRef = iNextOrderRef;
	sprintf(m_EXECORDER_REF, "%d", 1);
	sprintf(m_FORQUOTE_REF, "%d", 1);
	sprintf(m_QUOTE_REF, "%d", 1);
	//获取当前交易日
	cout << "--->>> 获取当前交易日 = " << m_pTraderApi->GetTradingDay() << endl;
	///投资者结算结果确认
	ReqSettlementInfoConfirm();
    emit traderLogined(m_index);
	emit traderStatusUpdated(m_index, QString::fromLocal8Bit("登录成功"));
}

void CTrader::ReqSettlementInfoConfirm()
{
	CThostFtdcSettlementInfoConfirmField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.BrokerID, m_BROKER_ID);
	strcpy(req.InvestorID, m_INVESTOR_ID);
	int iResult = m_pTraderApi->ReqSettlementInfoConfirm(&req, ++m_iRequestID);
	cout << "--->>> 投资者结算结果确认: " << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
}

void CTrader::ReqQryTradingAccount()
{
	CThostFtdcQryTradingAccountField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.BrokerID, m_BROKER_ID);
	strcpy(req.InvestorID, m_INVESTOR_ID);
	while (true)
	{
		int iResult = m_pTraderApi->ReqQryTradingAccount(&req, ++m_iRequestID);
		if (!IsFlowControl(iResult))
		{
			cout << "--->>> 请求查询资金账户: "  << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
			break;
		}
		else
		{
			cout << "--->>> 请求查询资金账户: "  << iResult << ", 受到流控" << endl;
			QThread::sleep(1);
		}
	} // while
}

void CTrader::rspQryTradingAccount(double balance, double positionProfit, double closeProfit)
{
	cout << "--->>> 已经查询到用户持仓"<< balance << QThread::currentThreadId() << endl;
	emit traderBalanceUpdated(m_index, balance, positionProfit, closeProfit);
}

void CTrader::ReqOrderInsert(TThostFtdcInstrumentIDType INSTRUMENT_ID, TThostFtdcDirectionType DIRECTION, 
                             TThostFtdcVolumeType VOLUME, TThostFtdcPriceType LIMIT_PRICE, 
                             TThostFtdcOffsetFlagType OFFSET_FLAG)
{
	CThostFtdcInputOrderField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.BrokerID, m_BROKER_ID);        //经纪公司代码
	strcpy(req.InvestorID, m_INVESTOR_ID);    //投资者代码
	strcpy(req.InstrumentID, INSTRUMENT_ID);  //合约代码
    sprintf(m_ORDER_REF, "%012d", m_iNextOrderRef++);
    strcpy(req.OrderRef, m_ORDER_REF);        //报单引用
	req.Direction = DIRECTION;            //买卖方向 
	req.CombOffsetFlag[0] = OFFSET_FLAG;  //组合开平标志
	req.LimitPrice = LIMIT_PRICE;         //价格
	req.VolumeTotalOriginal = VOLUME;     //数量
	req.OrderPriceType = THOST_FTDC_OPT_LimitPrice;     //报单价格条件: 限价
	req.TimeCondition = THOST_FTDC_TC_GFD;              //有效期类型: 当日有效
	req.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;   //组合投机套保标志
	req.ContingentCondition = THOST_FTDC_CC_Immediately;  //触发条件: 立即
	req.VolumeCondition = THOST_FTDC_VC_AV;               //成交量类型: 任何数量
	req.MinVolume = 0;                                    //最小成交量: 0
	req.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;  //强平原因: 非强平
	req.IsAutoSuspend = 0;                                //自动挂起标志: 否
	req.UserForceClose = 0;                               //用户强评标志: 否
    req.StopPrice = 0;        //止损价
    req.GTDDate[0] = '\0';    //GTD日期
    strcpy(req.UserID, m_INVESTOR_ID);
	///业务单元//	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号//	TThostFtdcRequestIDType	RequestID;

	int iResult = m_pTraderApi->ReqOrderInsert(&req, ++m_iRequestID);
	cerr << "--->>> 报单录入请求: " << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
}

void CTrader::ReqOrderAction(CThostFtdcOrderField *pOrder)
{
	static bool ORDER_ACTION_SENT = false;		//是否发送了报单
	if (ORDER_ACTION_SENT)
		return;

	CThostFtdcInputOrderActionField req;
	memset(&req, 0, sizeof(req));
	///经纪公司代码
	strcpy(req.BrokerID, pOrder->BrokerID);
	///投资者代码
	strcpy(req.InvestorID, pOrder->InvestorID);
	///报单操作引用
//	TThostFtdcOrderActionRefType	OrderActionRef;
	///报单引用
	strcpy(req.OrderRef, pOrder->OrderRef);
	///请求编号
//	TThostFtdcRequestIDType	RequestID;
	///前置编号
	req.FrontID = m_FRONT_ID;
	///会话编号
	req.SessionID = m_SESSION_ID;
	///交易所代码
//	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
//	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	req.ActionFlag = THOST_FTDC_AF_Delete;
	///价格
//	TThostFtdcPriceType	LimitPrice;
	///数量变化
//	TThostFtdcVolumeType	VolumeChange;
	///用户代码
//	TThostFtdcUserIDType	UserID;
	///合约代码
	strcpy(req.InstrumentID, pOrder->InstrumentID);

	int iResult = m_pTraderApi->ReqOrderAction(&req, ++m_iRequestID);
	cerr << "--->>> 报单操作请求: "  << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
	ORDER_ACTION_SENT = true;
}

bool CTrader::IsMyOrder(CThostFtdcOrderField *pOrder)
{
	return ((pOrder->FrontID == m_FRONT_ID) &&
			(pOrder->SessionID == m_SESSION_ID) &&
			(strcmp(pOrder->OrderRef, m_ORDER_REF) == 0));
}

void CTrader::rspTradingAciton()
{
}

void CTrader::FollowRtnTrade(CThostFtdcTradeField tradeField)
{
    TThostFtdcVolumeType volume = int(tradeField.Volume*2.0);
    TThostFtdcDirectionType direct = tradeField.Direction;
    if (m_followDirect == 1) // 反向跟单
    {
        direct = tradeField.Direction==THOST_FTDC_D_Buy?THOST_FTDC_D_Sell:THOST_FTDC_D_Buy;
    }
    ReqOrderInsert(tradeField.InstrumentID, direct, volume, tradeField.Price, tradeField.OffsetFlag);
    emit eventTableUpdated(QString::fromLocal8Bit("主账号跟单：合约%1,方向:%2,数量:%3,价格:%4")
        .arg(tradeField.InstrumentID).arg(direct).arg(volume).arg(tradeField.Price));
}

void CTrader::ProcessTradeEvent(CThostFtdcTradeField tradeField)
{
    if(m_index == -1) // 主账号成交
    {
        emit eventTableUpdated(QString::fromLocal8Bit("主账号成交：合约%1,方向:%2,数量:%3")
            .arg(tradeField.InstrumentID).arg(tradeField.Direction).arg(tradeField.Volume));
    }
    else
    {
        emit RtnTradeEvent(tradeField);
    }
}


// 下面的不管
void CTrader::ReqQryInstrument(TThostFtdcInstrumentIDType instrument_id)
{
	CThostFtdcQryInstrumentField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.InstrumentID, instrument_id);
	while (true)
	{
		int iResult = m_pTraderApi->ReqQryInstrument(&req, ++m_iRequestID);
		if (!IsFlowControl(iResult))
		{
			cout << "--->>> 请求查询合约: "  << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
			break;
		}
		else
		{
			cout << "--->>> 请求查询合约: "  << iResult << ", 受到流控" << endl;
			QThread::sleep(1);
		}
	} // while
}

void CTrader::ReqQryInvestorPosition(TThostFtdcInstrumentIDType instrument_id)
{
	CThostFtdcQryInvestorPositionField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.BrokerID, m_BROKER_ID);
	strcpy(req.InvestorID, m_INVESTOR_ID);
	strcpy(req.InstrumentID, instrument_id);
	while (true)
	{
		int iResult = m_pTraderApi->ReqQryInvestorPosition(&req, ++m_iRequestID);
		if (!IsFlowControl(iResult))
		{
			cerr << "--->>> 请求查询投资者持仓: "  << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
			break;
		}
		else
		{
			cerr << "--->>> 请求查询投资者持仓: "  << iResult << ", 受到流控" << endl;
			QThread::sleep(1);
		}
	} // while
}

//执行宣告录入请求
void CTrader::ReqExecOrderInsert(TThostFtdcInstrumentIDType INSTRUMENT_ID)
{
	CThostFtdcInputExecOrderField req;
	memset(&req, 0, sizeof(req));
	///经纪公司代码
	strcpy(req.BrokerID, m_BROKER_ID);
	///投资者代码
	strcpy(req.InvestorID, m_INVESTOR_ID);
	///合约代码
	strcpy(req.InstrumentID, INSTRUMENT_ID);
	///报单引用
	strcpy(req.ExecOrderRef, m_EXECORDER_REF);
	///用户代码
	//	TThostFtdcUserIDType	UserID;
	///数量
	req.Volume=1;
	///请求编号
	//TThostFtdcRequestIDType	RequestID;
	///业务单元
	//TThostFtdcBusinessUnitType	BusinessUnit;
	///开平标志
	req.OffsetFlag=THOST_FTDC_OF_Close;//如果是上期所，需要填平今或平昨
	///投机套保标志
	req.HedgeFlag=THOST_FTDC_HF_Speculation;
	///执行类型
	req.ActionType=THOST_FTDC_ACTP_Exec;//如果放弃执行则填THOST_FTDC_ACTP_Abandon
	///保留头寸申请的持仓方向
	req.PosiDirection=THOST_FTDC_PD_Long;
	///期权行权后是否保留期货头寸的标记
	req.ReservePositionFlag=THOST_FTDC_EOPF_UnReserve;//这是中金所的填法，大商所郑商所填THOST_FTDC_EOPF_Reserve
	///期权行权后生成的头寸是否自动平仓
	req.CloseFlag=THOST_FTDC_EOCF_AutoClose;//这是中金所的填法，大商所郑商所填THOST_FTDC_EOCF_NotToClose

	int iResult = m_pTraderApi->ReqExecOrderInsert(&req, ++m_iRequestID);
	cerr << "--->>> 执行宣告录入请求: " << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
}

//询价录入请求
void CTrader::ReqForQuoteInsert(TThostFtdcInstrumentIDType INSTRUMENT_ID)
{
	CThostFtdcInputForQuoteField req;
	memset(&req, 0, sizeof(req));
	///经纪公司代码
	strcpy(req.BrokerID, m_BROKER_ID);
	///投资者代码
	strcpy(req.InvestorID, m_INVESTOR_ID);
	///合约代码
	strcpy(req.InstrumentID, INSTRUMENT_ID);
	///报单引用
	strcpy(req.ForQuoteRef, m_EXECORDER_REF);
	///用户代码
	//	TThostFtdcUserIDType	UserID;

	int iResult = m_pTraderApi->ReqForQuoteInsert(&req, ++m_iRequestID);
	cerr << "--->>> 询价录入请求: " << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
}
//报价录入请求
void CTrader::ReqQuoteInsert(TThostFtdcInstrumentIDType INSTRUMENT_ID, TThostFtdcPriceType LIMIT_PRICE)
{
	CThostFtdcInputQuoteField req;
	memset(&req, 0, sizeof(req));
	///经纪公司代码
	strcpy(req.BrokerID, m_BROKER_ID);
	///投资者代码
	strcpy(req.InvestorID, m_INVESTOR_ID);
	///合约代码
	strcpy(req.InstrumentID, INSTRUMENT_ID);
	///报单引用
	strcpy(req.QuoteRef, m_QUOTE_REF);
	///卖价格
	req.AskPrice=LIMIT_PRICE;
	///买价格
	req.BidPrice=LIMIT_PRICE-1.0;
	///卖数量
	req.AskVolume=1;
	///买数量
	req.BidVolume=1;
	///请求编号
	//TThostFtdcRequestIDType	RequestID;
	///业务单元
	//TThostFtdcBusinessUnitType	BusinessUnit;
	///卖开平标志
	req.AskOffsetFlag=THOST_FTDC_OF_Open;
	///买开平标志
	req.BidOffsetFlag=THOST_FTDC_OF_Open;
	///卖投机套保标志
	req.AskHedgeFlag=THOST_FTDC_HF_Speculation;
	///买投机套保标志
	req.BidHedgeFlag=THOST_FTDC_HF_Speculation;
	
	int iResult = m_pTraderApi->ReqQuoteInsert(&req, ++m_iRequestID);
	cerr << "--->>> 报价录入请求: " << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
}

void CTrader::ReqExecOrderAction(CThostFtdcExecOrderField *pExecOrder)
{
	static bool EXECORDER_ACTION_SENT = false;		//是否发送了报单
	if (EXECORDER_ACTION_SENT)
		return;

	CThostFtdcInputExecOrderActionField req;
	memset(&req, 0, sizeof(req));

	///经纪公司代码
	strcpy(req.BrokerID,pExecOrder->BrokerID);
	///投资者代码
	strcpy(req.InvestorID,pExecOrder->InvestorID);
	///执行宣告操作引用
	//TThostFtdcOrderActionRefType	ExecOrderActionRef;
	///执行宣告引用
	strcpy(req.ExecOrderRef,pExecOrder->ExecOrderRef);
	///请求编号
	//TThostFtdcRequestIDType	RequestID;
	///前置编号
	req.FrontID=m_FRONT_ID;
	///会话编号
	req.SessionID=m_SESSION_ID;
	///交易所代码
	//TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告操作编号
	//TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///操作标志
	req.ActionFlag=THOST_FTDC_AF_Delete;
	///用户代码
	//TThostFtdcUserIDType	UserID;
	///合约代码
	strcpy(req.InstrumentID,pExecOrder->InstrumentID);

	int iResult = m_pTraderApi->ReqExecOrderAction(&req, ++m_iRequestID);
	cerr << "--->>> 执行宣告操作请求: "  << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
	EXECORDER_ACTION_SENT = true;
}

void CTrader::ReqQuoteAction(CThostFtdcQuoteField *pQuote)
{
	static bool QUOTE_ACTION_SENT = false;		//是否发送了报单
	if (QUOTE_ACTION_SENT)
		return;

	CThostFtdcInputQuoteActionField req;
	memset(&req, 0, sizeof(req));
	///经纪公司代码
	strcpy(req.BrokerID, pQuote->BrokerID);
	///投资者代码
	strcpy(req.InvestorID, pQuote->InvestorID);
	///报价操作引用
	//TThostFtdcOrderActionRefType	QuoteActionRef;
	///报价引用
	strcpy(req.QuoteRef,pQuote->QuoteRef);
	///请求编号
	//TThostFtdcRequestIDType	RequestID;
	///前置编号
	req.FrontID=m_FRONT_ID;
	///会话编号
	req.SessionID=m_SESSION_ID;
	///交易所代码
	//TThostFtdcExchangeIDType	ExchangeID;
	///报价操作编号
	//TThostFtdcOrderSysIDType	QuoteSysID;
	///操作标志
	req.ActionFlag=THOST_FTDC_AF_Delete;
	///用户代码
	//TThostFtdcUserIDType	UserID;
	///合约代码
	strcpy(req.InstrumentID,pQuote->InstrumentID);

	int iResult = m_pTraderApi->ReqQuoteAction(&req, ++m_iRequestID);
	cerr << "--->>> 报价操作请求: "  << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
	QUOTE_ACTION_SENT = true;
}

bool CTrader::IsMyExecOrder(CThostFtdcExecOrderField *pExecOrder)
{
	return ((pExecOrder->FrontID == m_FRONT_ID) &&
		(pExecOrder->SessionID == m_SESSION_ID) &&
		(strcmp(pExecOrder->ExecOrderRef, m_EXECORDER_REF) == 0));
}

bool CTrader::IsMyQuote(CThostFtdcQuoteField *pQuote)
{
	return ((pQuote->FrontID == m_FRONT_ID) &&
		(pQuote->SessionID == m_SESSION_ID) &&
		(strcmp(pQuote->QuoteRef, m_QUOTE_REF) == 0));
}