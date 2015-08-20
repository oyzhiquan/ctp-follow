#include <qt_windows.h>
#include <iostream>
using namespace std;

#include "include\TraderSpi.h"


void CTraderSpi::OnFrontConnected()
{
	qDebug() << "<<<---" << "OnFrontConnected:" << QThread::currentThreadId() <<endl;
	///用户登录请求
	// ReqUserLogin();
	emit frontConnected();
}

void CTraderSpi:: OnFrontDisconnected(int nReason)
{
	qDebug() << "<<<---" << "OnFrontDisconnected" << endl;
	qDebug() << "<<<--- Reason = " << nReason << endl;
	emit frontDisconnected();
}

void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspUserLogin:" << QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
		iNextOrderRef++;
		
		emit rspUserLogin(pRspUserLogin->FrontID, pRspUserLogin->SessionID, iNextOrderRef);
	}
}

void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspSettlementInfoConfirm:" << QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		emit rspSettlementInfoConfirm();
	}
}

void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspOrderInsert:" << QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		//emit rspOrderInsert();
	}
}

void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspOrderAction:" << QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		//emit rspOrderAciton();
	}
}

///报单通知
void CTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder)
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
void CTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade)
{
	qDebug() << "<<<---" << "OnRtnTrade:"  <<  QThread::currentThreadId() <<endl;
	qDebug() << pTrade->InvestorID << ":" << pTrade->Direction <<":" << pTrade->InstrumentID << ":" << pTrade->Price << endl;
    emit RtnTradeEvent(*pTrade);
}

void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspQryTradingAccount:"  <<  QThread::currentThreadId() <<endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		// 静态权益 = 上日结算 - 出金金额 + 入金金额
		double preBalance = pTradingAccount->PreBalance - pTradingAccount->Withdraw + pTradingAccount->Deposit;
		cout << "preBalance:"<<preBalance<< endl;
		// 动态权益 = 静态权益 + 平仓盈亏 + 持仓盈亏 -手续费
		double currentBalance = preBalance + pTradingAccount->CloseProfit + pTradingAccount->PositionProfit - pTradingAccount->Commission;	
		cout << "currentBalance" << currentBalance << endl;
		emit rspQryTradingAccount(currentBalance, pTradingAccount->CloseProfit, pTradingAccount->PositionProfit);
	}
}
		
void CTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
	qDebug() << "<<<---" << "OnHeartBeatWarning" <<  QThread::currentThreadId() <<endl;
	qDebug() << "<<<--- nTimerLapse = " << nTimeLapse << endl;
}

void CTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	qDebug() << "<<<---" << "OnRspError" <<  QThread::currentThreadId() <<endl;
	IsErrorRspInfo(pRspInfo);
}

bool CTraderSpi::IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo)
{
	// 如果ErrorID != 0, 说明收到了错误的响应
	bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
	if (bResult)
	{
		emit rspErrorInfo();
		qDebug() << "<<<--- ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
	}
	return bResult;
}

bool CTraderSpi::IsTradingOrder(CThostFtdcOrderField *pOrder)
{
	return ((pOrder->OrderStatus != THOST_FTDC_OST_PartTradedNotQueueing) &&
			(pOrder->OrderStatus != THOST_FTDC_OST_Canceled) &&
			(pOrder->OrderStatus != THOST_FTDC_OST_AllTraded));
}


// 下面的暂时不管

void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << "OnRspQryInstrument" << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		//ReqQryTradingAccount();
	}
}

void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cerr << "--->>> " << "OnRspQryInvestorPosition" << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
	{
		///报单录入请求
		//ReqOrderInsert();
		//执行宣告录入请求
		//ReqExecOrderInsert();
		//询价录入
		//ReqForQuoteInsert();
		//做市商报价录入
		//ReqQuoteInsert();
	}
}

void CTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	//如果执行宣告正确，则不会进入该回调
	cerr << "--->>> " << "OnRspExecOrderInsert" << endl;
	IsErrorRspInfo(pRspInfo);
}

void CTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	//如果询价正确，则不会进入该回调
	cerr << "--->>> " << "OnRspForQuoteInsert" << endl;
	IsErrorRspInfo(pRspInfo);
}

void CTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	//如果报价正确，则不会进入该回调
	cerr << "--->>> " << "OnRspQuoteInsert" << endl;
	IsErrorRspInfo(pRspInfo);
}

void CTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInpuExectOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	//正确的撤单操作，不会进入该回调
	cerr << "--->>> " << "OnRspExecOrderAction" << endl;
	IsErrorRspInfo(pRspInfo);
}

void CTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInpuQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	//正确的撤单操作，不会进入该回调
	cerr << "--->>> " << "OnRspQuoteAction" << endl;
	IsErrorRspInfo(pRspInfo);
}


//执行宣告通知
void CTraderSpi::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder)
{
	cerr << "--->>> " << "OnRtnExecOrder"  << endl;
	//if (IsMyExecOrder(pExecOrder))
	//{
	//	if (IsTradingExecOrder(pExecOrder))
	//		ReqExecOrderAction(pExecOrder);
	//	else if (pExecOrder->ExecResult == THOST_FTDC_OER_Canceled)
	//		cout << "--->>> 执行宣告撤单成功" << endl;
	//}
}

//询价通知
void CTraderSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
	//上期所中金所询价通知通过该接口返回；只有做市商客户可以收到该通知
	cerr << "--->>> " << "OnRtnForQuoteRsp"  << endl;
}

//报价通知
void CTraderSpi::OnRtnQuote(CThostFtdcQuoteField *pQuote)
{
	cerr << "--->>> " << "OnRtnQuote"  << endl;
	//if (IsMyQuote(pQuote))
	//{
	//	if (IsTradingQuote(pQuote))
	//		ReqQuoteAction(pQuote);
	//	else if (pQuote->QuoteStatus == THOST_FTDC_OST_Canceled)
	//		cout << "--->>> 报价撤单成功" << endl;
	//}
}

bool CTraderSpi::IsTradingExecOrder(CThostFtdcExecOrderField *pExecOrder)
{
	return (pExecOrder->ExecResult != THOST_FTDC_OER_Canceled);
}

bool CTraderSpi::IsTradingQuote(CThostFtdcQuoteField *pQuote)
{
	return (pQuote->QuoteStatus != THOST_FTDC_OST_Canceled);
}
