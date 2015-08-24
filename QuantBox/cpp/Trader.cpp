#include "include\Trader.h"
#include <QDir>
#include <QtSql>
#include <iostream>
using namespace std;

MainTrader::MainTrader(Account &account)
{
	cout << "CTrader init:"<< QThread::currentThreadId() <<endl;

	strcpy(m_FRONT_ADDR, account.tdFrontAddr);
	strcpy(m_BROKER_ID, account.brokerID);
	strcpy(m_INVESTOR_ID, account.inverstorID);
	strcpy(m_PASSWORD, account.password);
	m_iRequestID = 0;

	QString flowPath = QString::fromLocal8Bit("%1\\%2\\")
        .arg(QCoreApplication::applicationDirPath().toStdString().c_str()).arg(m_INVESTOR_ID);
    QDir dir;
    if(!dir.exists(flowPath))
    {
        dir.mkdir(flowPath);
    }
    m_pTraderApi = CThostFtdcTraderApi::CreateFtdcTraderApi(flowPath.toStdString().c_str()); // 创建UserApi
    m_pTraderSpi = new MainTraderSpi();
    m_followStrategys.clear();
}

MainTrader::~MainTrader()
{
	cout << "CTrader destroy:" << QThread::currentThreadId() << endl;
    emit TraderStatusUpdated(QString::fromLocal8Bit("账户已退出"));
    emit TraderBalanceUpdated(0.0, 0.0, 0.0);
    emit EventTableUpdated(QString::fromLocal8Bit("账号%1已经退出登录").arg(m_INVESTOR_ID));
    m_pTraderApi->Release();  // 一定要先释放交易api
    delete m_pTraderSpi;
}

void MainTrader::LoadStrategy()
{
    QSqlDatabase db = QSqlDatabase::database();
    if(!db.open())
    {
        qDebug() << "策略加载失败" << endl;
    }
	QSqlQuery query;
    Strategy strategy;
    m_orderStrategys.clear();
	query.exec("select id, follow_type, action_sec, price_type, price_jump, \
               action_times, final_type from strategy order by id");
    while (query.next())
    {
        strategy.id = query.value(0).toInt();
        strategy.followType = query.value(1).toInt();
        strategy.actionSec = query.value(2).toInt();
        strategy.priceType = query.value(3).toInt();
        strategy.priceJump = query.value(4).toInt();
        strategy.actionTimes = query.value(5).toInt();
        strategy.finalType = query.value(6).toInt();
        m_orderStrategys.push_back(strategy);
    }
    db.close();
}

void MainTrader::SetThread(QThread * mainThread)
{
	m_pThread = mainThread;
	this->moveToThread(mainThread);
}

void MainTrader::AddFollowStrategy(const char* investorID, FollowStrategy &followStrategy)
{
    m_followStrategys[investorID] = followStrategy;
}

bool MainTrader::IsFlowControl(int iResult)
{
	return ((iResult == -2) || (iResult == -3));
}

void MainTrader::ReqConnect()
{
	cout << "user Login:"<< QThread::currentThreadId() <<endl;

    QObject::connect(m_pTraderSpi, &MainTraderSpi::FrontConnected, this, &MainTrader::ReqUserLogin);
	QObject::connect(m_pTraderSpi, &MainTraderSpi::UserLogined, this, &MainTrader::RspUserLogin);
	QObject::connect(m_pTraderSpi, &MainTraderSpi::SettlementInfoConfirmed, this, &MainTrader::ReqQryTradingAccount);
    QObject::connect(m_pTraderSpi, &MainTraderSpi::TraderBalanceUpdated, this, &MainTrader::RspQryTradingAccount);
    QObject::connect(m_pTraderSpi, &MainTraderSpi::RtnTradeEvent, this, &MainTrader::ProcessTradeEvent);

	m_pTraderApi->RegisterSpi((CThostFtdcTraderSpi*)m_pTraderSpi);		// 注册事件类
	m_pTraderApi->SubscribePublicTopic(THOST_TERT_QUICK);				// 注册公有流
	m_pTraderApi->SubscribePrivateTopic(THOST_TERT_QUICK);				// 注册私有流
	m_pTraderApi->RegisterFront(m_FRONT_ADDR);							// connect
	m_pTraderApi->Init();
	// m_pTraderApi->Join();
	emit TraderStatusUpdated(QString::fromLocal8Bit("已连接交易服务器"));
}

void MainTrader::ReqDisconnect()
{
    m_pThread->quit();
}

void MainTrader::ReqUserLogin()
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
		emit TraderStatusUpdated(QString::fromLocal8Bit("成功发送登录请求"));
	}
	else
	{
        cout << "--->>> 发送用户登录请求: 失败" << QThread::currentThreadId() << endl;
        emit TraderStatusUpdated(QString::fromLocal8Bit("发送登录请求失败"));
	}
}

void MainTrader::RspUserLogin(int front_id ,int session_id, int iNextOrderRef)
{
	m_FRONT_ID = front_id;
	m_SESSION_ID = session_id;
    m_iNextOrderRef = iNextOrderRef;
	//获取当前交易日
	cout << "--->>> 获取当前交易日 = " << m_pTraderApi->GetTradingDay() << endl;
	///投资者结算结果确认
	ReqSettlementInfoConfirm();
    emit TraderLogined();
	emit TraderStatusUpdated(QString::fromLocal8Bit("登录成功"));
}

void MainTrader::ReqSettlementInfoConfirm()
{
	CThostFtdcSettlementInfoConfirmField req;
	memset(&req, 0, sizeof(req));
	strcpy(req.BrokerID, m_BROKER_ID);
	strcpy(req.InvestorID, m_INVESTOR_ID);
	int iResult = m_pTraderApi->ReqSettlementInfoConfirm(&req, ++m_iRequestID);
	cout << "--->>> 投资者结算结果确认: " << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
}

void MainTrader::ReqQryTradingAccount()
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

void MainTrader::RspQryTradingAccount(double balance, double positionProfit, double closeProfit)
{
	cout << "--->>> 已经查询到用户持仓"<< balance << QThread::currentThreadId() << endl;
	emit TraderBalanceUpdated(balance, positionProfit, closeProfit);
}

void MainTrader::ReqOrderInsert(TThostFtdcInstrumentIDType INSTRUMENT_ID, TThostFtdcDirectionType DIRECTION, 
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

void MainTrader::ReqOrderAction(CThostFtdcOrderField *pOrder)
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

bool MainTrader::IsMyOrder(CThostFtdcOrderField *pOrder)
{
	return ((pOrder->FrontID == m_FRONT_ID) &&
			(pOrder->SessionID == m_SESSION_ID) &&
			(strcmp(pOrder->OrderRef, m_ORDER_REF) == 0));
}

void MainTrader::RspTradingAciton()
{
}

void MainTrader::FollowRtnTrade(CThostFtdcTradeField tradeField)
{
    FollowStrategy strategy = m_followStrategys[tradeField.InvestorID];
    TThostFtdcVolumeType volume = int(tradeField.Volume*strategy.ratio);
    TThostFtdcDirectionType direct = tradeField.Direction;
    if (strategy.direct == 1) // 反向跟单
    {
        direct = tradeField.Direction==THOST_FTDC_D_Buy?THOST_FTDC_D_Sell:THOST_FTDC_D_Buy;
    }
    ReqOrderInsert(tradeField.InstrumentID, direct, volume, tradeField.Price, tradeField.OffsetFlag);
    emit EventTableUpdated(QString::fromLocal8Bit("主账号跟单：合约%1,方向:%2,数量:%3,价格:%4")
        .arg(tradeField.InstrumentID).arg(direct).arg(volume).arg(tradeField.Price));
}

void MainTrader::ProcessTradeEvent(CThostFtdcTradeField tradeField)
{
    emit EventTableUpdated(QString::fromLocal8Bit("主账号成交：合约%1,方向:%2,数量:%3")
        .arg(tradeField.InstrumentID).arg(tradeField.Direction).arg(tradeField.Volume));
}
