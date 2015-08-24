#include <qt_windows.h>
#include "include\TraderSpi.h"


void MainTraderSpi::OnFrontConnected()
{
	qDebug() << "<<<---" << "OnFrontConnected:" << QThread::currentThreadId() <<endl;
	emit FrontConnected();
}

void MainTraderSpi:: OnFrontDisconnected(int nReason)
{
	qDebug() << "<<<---" << "OnFrontDisconnected: Reason = " << nReason << endl;
}

void MainTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspUserLogin:" << QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
		iNextOrderRef++;
		emit UserLogined(pRspUserLogin->FrontID, pRspUserLogin->SessionID, iNextOrderRef);
	}
}

void MainTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, 
                                               CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspSettlementInfoConfirm:" << QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		emit SettlementInfoConfirmed();
	}
}

void MainTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, 
                                     CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspOrderInsert:" << QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		//emit rspOrderInsert();
	}
}

void MainTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, 
                                     CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspOrderAction:" << QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		//emit rspOrderAciton();
	}
}

///报单通知
void MainTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
	qDebug() << "<<<---" << "OnRtnOrder:"  <<  QThread::currentThreadId() <<endl;
	/*if (IsMyOrder(pOrder))
	{
		if (IsTradingOrder(pOrder))
			ReqOrderAction(pOrder);
		else if (pOrder->OrderStatus == THOST_FTDC_OST_Canceled)
			cout << "--->>> 撤单成功" << endl;
	}*/
}

///成交通知
void MainTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade)
{
	qDebug() << "<<<---" << "OnRtnTrade:"  <<  QThread::currentThreadId() <<endl;
	qDebug() << pTrade->InvestorID << ":" << pTrade->Direction <<":" 
        << pTrade->InstrumentID << ":" << pTrade->Price << endl;
    emit RtnTradeEvent(*pTrade);
}

void MainTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, 
                                           CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspQryTradingAccount:"  <<  QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		// 静态权益 = 上日结算 - 出金金额 + 入金金额
		double preBalance = pTradingAccount->PreBalance - pTradingAccount->Withdraw + pTradingAccount->Deposit;
		// 动态权益 = 静态权益 + 平仓盈亏 + 持仓盈亏 -手续费
		double currentBalance = preBalance + pTradingAccount->CloseProfit + pTradingAccount->PositionProfit - pTradingAccount->Commission;	
		emit TraderBalanceUpdated(currentBalance, pTradingAccount->CloseProfit, pTradingAccount->PositionProfit);
	}
}
		
void MainTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
	qDebug() << "<<<---" << "OnHeartBeatWarning" <<  QThread::currentThreadId() <<endl;
	qDebug() << "<<<--- nTimerLapse = " << nTimeLapse << endl;
}

void MainTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspError" <<  QThread::currentThreadId() <<endl;
	IsErrorRspInfo(pRspInfo);
}

bool MainTraderSpi::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult)
	{
		// emit RspErrorInfo();
		qDebug() << "<<<--- ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
	}
	return bResult;
}

bool MainTraderSpi::IsTradingOrder(CThostFtdcOrderField *pOrder)
{
	return ((pOrder->OrderStatus != THOST_FTDC_OST_PartTradedNotQueueing) &&
			(pOrder->OrderStatus != THOST_FTDC_OST_Canceled) &&
			(pOrder->OrderStatus != THOST_FTDC_OST_AllTraded));
}


//====================== FollowTraderSpi =====================
FollowTraderSpi::FollowTraderSpi()
{
}

FollowTraderSpi::~FollowTraderSpi()
{
    qDebug() << "FollowTraderSpi destroy:" << QThread::currentThreadId() << endl;
    emit TraderStatusUpdated(m_index, QString::fromLocal8Bit("账户已退出"));
    emit TraderBalanceUpdated(m_index, 0.0, 0.0, 0.0);
    emit EventTableUpdated(QString::fromLocal8Bit("账号%1已经退出登录").arg(m_INVESTOR_ID));
    m_pTraderApi->Release();  // 一定要先释放交易api
}

void FollowTraderSpi::Init(int index, const char* frontAddr, const char* brokerID, 
                           const char* investorID, const char* password)
{
    m_index = index;
    strcpy(m_FRONT_ADDR, frontAddr);
    strcpy(m_BROKER_ID, brokerID);
    strcpy(m_INVESTOR_ID, investorID);
    strcpy(m_PASSWORD, password);
    m_iRequestID = 0;
}

void FollowTraderSpi::ReqConnect()
{
    qDebug() << "<<<---" << "ReqConnect:"<< QThread::currentThreadId() <<endl;

    QString flowPath = QString::fromLocal8Bit("%1\\%2\\")
        .arg(QCoreApplication::applicationDirPath().toStdString().c_str()).arg(m_INVESTOR_ID);
    QDir dir;
    if(!dir.exists(flowPath))
    {
        dir.mkdir(flowPath);
    }
    m_pTraderApi = CThostFtdcTraderApi::CreateFtdcTraderApi(flowPath.toStdString().c_str());  // 创建UserApi

    m_pTraderApi->RegisterSpi((CThostFtdcTraderSpi*)this);  	// 注册事件类
    m_pTraderApi->SubscribePublicTopic(THOST_TERT_QUICK);		// 注册公有流
    m_pTraderApi->SubscribePrivateTopic(THOST_TERT_QUICK);		// 注册私有流
    m_pTraderApi->RegisterFront(m_FRONT_ADDR);					// connect
    m_pTraderApi->Init();
    emit TraderStatusUpdated(m_index, QString::fromLocal8Bit("已连接交易服务器"));
}

void FollowTraderSpi::OnFrontConnected()
{
	qDebug() << "<<<---" << "OnFrontConnected:" << QThread::currentThreadId() <<endl;
	///用户登录请求
	ReqUserLogin();
}

void FollowTraderSpi:: OnFrontDisconnected(int nReason)
{
	qDebug() << "<<<---" << "OnFrontDisconnected:" << "Reason = " << nReason << endl;
}

void FollowTraderSpi::ReqUserLogin()
{
    CThostFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, m_BROKER_ID);
    strcpy(req.UserID, m_INVESTOR_ID);
    strcpy(req.Password, m_PASSWORD);
    int iResult = m_pTraderApi->ReqUserLogin(&req, ++m_iRequestID);
    if(iResult==0)
    {
        qDebug() << "<<<--- 发送用户登录请求: 成功" << QThread::currentThreadId() << endl;
        emit TraderStatusUpdated(m_index, QString::fromLocal8Bit("成功发送登录请求"));
    }
    else
    {
        qDebug() << "<<<--- 发送用户登录请求: 失败" << QThread::currentThreadId() << endl;
        emit TraderStatusUpdated(m_index, QString::fromLocal8Bit("发送登录请求失败"));
    }
}

void FollowTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspUserLogin:" << QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
		iNextOrderRef++;

        m_FRONT_ID = pRspUserLogin->FrontID;
        m_SESSION_ID = pRspUserLogin->SessionID;
        m_iNextOrderRef = iNextOrderRef;
        //获取当前交易日
        qDebug() << "<<<--- 获取当前交易日 = " << m_pTraderApi->GetTradingDay() << endl;
        ///投资者结算结果确认
        ReqSettlementInfoConfirm();
        emit TraderLogined(m_index);
        emit TraderStatusUpdated(m_index, QString::fromLocal8Bit("登录成功"));
	}
}

void FollowTraderSpi::ReqSettlementInfoConfirm()
{
    CThostFtdcSettlementInfoConfirmField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, m_BROKER_ID);
    strcpy(req.InvestorID, m_INVESTOR_ID);
    int iResult = m_pTraderApi->ReqSettlementInfoConfirm(&req, ++m_iRequestID);
    qDebug() << "<<<--- 投资者结算结果确认: " << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
}

void FollowTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, 
                                                 CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspSettlementInfoConfirm:" << QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		ReqQryTradingAccount();
	}
}

void FollowTraderSpi::ReqQryTradingAccount()
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
            qDebug() << "--->>> 请求查询资金账户: "  << iResult << ((iResult == 0) ? ", 成功" : ", 失败") << endl;
            break;
        }
        else
        {
            qDebug() << "--->>> 请求查询资金账户: "  << iResult << ", 受到流控" << endl;
            QThread::sleep(1);
        }
    } // while
}

void FollowTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, 
                                             CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    qDebug() << "<<<---" << "OnRspQryTradingAccount:"  <<  QThread::currentThreadId() <<endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        // 静态权益 = 上日结算 - 出金金额 + 入金金额
        double preBalance = pTradingAccount->PreBalance - pTradingAccount->Withdraw + pTradingAccount->Deposit;
        // 动态权益 = 静态权益 + 平仓盈亏 + 持仓盈亏 -手续费
        double currentBalance = preBalance + pTradingAccount->CloseProfit + pTradingAccount->PositionProfit - pTradingAccount->Commission;	
        emit TraderBalanceUpdated(m_index, currentBalance, pTradingAccount->CloseProfit, pTradingAccount->PositionProfit);
    }
}

///报单通知
void FollowTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
	qDebug() << "<<<---" << "OnRtnOrder:"  <<  QThread::currentThreadId() <<endl;
	/*if (IsMyOrder(pOrder))
	{
		if (IsTradingOrder(pOrder))
			ReqOrderAction(pOrder);
		else if (pOrder->OrderStatus == THOST_FTDC_OST_Canceled)
			cout << "--->>> 撤单成功" << endl;
	}*/
}

///成交通知
void FollowTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade)
{
	qDebug() << "<<<---" << "OnRtnTrade:"  <<  QThread::currentThreadId() <<endl;
	qDebug() << pTrade->InvestorID << ":" << pTrade->Direction <<":" << pTrade->InstrumentID << ":" << pTrade->Price << endl;
    emit RtnTradeEvent(*pTrade);
}
		
void FollowTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
	qDebug() << "<<<---" << "OnHeartBeatWarning" <<  QThread::currentThreadId() <<endl;
	qDebug() << "<<<--- nTimerLapse = " << nTimeLapse << endl;
}

void FollowTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspError" <<  QThread::currentThreadId() <<endl;
	IsErrorRspInfo(pRspInfo);
}

bool FollowTraderSpi::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult)
	{
		emit RspErrorInfo();
		qDebug() << "<<<--- ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
	}
	return bResult;
}

bool FollowTraderSpi::IsTradingOrder(CThostFtdcOrderField *pOrder)
{
	return ((pOrder->OrderStatus != THOST_FTDC_OST_PartTradedNotQueueing) &&
			(pOrder->OrderStatus != THOST_FTDC_OST_Canceled) &&
			(pOrder->OrderStatus != THOST_FTDC_OST_AllTraded));
}

bool FollowTraderSpi::IsFlowControl(int iResult)
{
    return ((iResult == -2) || (iResult == -3));
}
