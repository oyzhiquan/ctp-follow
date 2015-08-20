#pragma once
#include "ThostTraderApi\ThostFtdcTraderApi.h"
#include "include\TraderSpi.h"
#include <QtCore>

typedef struct
{
	char inverst_id[13];
	char password[41];
	char broker_id[11];
	char broker_name[20];
	char td_front_addr[101];
	int direct;
	float ratio;
} Account;

class CTrader: public QObject
{
	Q_OBJECT

public:
	CTrader(int index, Account accout);
	~CTrader();
	void SetThread(QThread * thread);

private:
	TThostFtdcAddressType m_FRONT_ADDR;						// 前置地址
	TThostFtdcBrokerIDType	m_BROKER_ID;					// 经纪公司代码
	TThostFtdcInvestorIDType m_INVESTOR_ID;					// 投资者代码
	TThostFtdcPasswordType  m_PASSWORD;						// 用户密码 
	int m_iRequestID;

	// 会话参数
	TThostFtdcFrontIDType	m_FRONT_ID;		//前置编号
	TThostFtdcSessionIDType	m_SESSION_ID;	//会话编号
    int m_iNextOrderRef;
	TThostFtdcOrderRefType	m_ORDER_REF;	//报单引用
	TThostFtdcOrderRefType	m_EXECORDER_REF;	//执行宣告引用
	TThostFtdcOrderRefType	m_FORQUOTE_REF;	//询价引用
	TThostFtdcOrderRefType	m_QUOTE_REF;	//报价引用

	CTraderSpi * m_pTraderSpi;
	CThostFtdcTraderApi* m_pTraderApi;

	int m_index;  // 0:主账号，1-N依次为跟踪账号
	char m_flowPath[100];
    int m_followDirect;
    float m_followRatio;

	QThread * m_pThread;

private:
	bool IsFlowControl(int iResult);

signals:
	void traderStatusUpdated(int index, QString message);
	void traderBalanceUpdated(int index, double balance, double closeProfit, double positionProfit);
    void eventTableUpdated(QString message);
	void RtnTradeEvent(CThostFtdcTradeField tradeField);
    void traderLogined(int index);

public slots:
	void ReqConnect();

    // 用户登出请求
	void ReqLogout();

	///用户登录请求
	void ReqUserLogin();
	void rspUserLogin(int front_id ,int session_id, int iNextOrderRef);
	///投资者结算结果确认
	void ReqSettlementInfoConfirm();
	///请求查询资金账户
	void ReqQryTradingAccount();
	void rspQryTradingAccount(double balance, double closeProfit, double positionProfit);


	///报单录入请求
	void ReqOrderInsert(TThostFtdcInstrumentIDType INSTRUMENT_ID, TThostFtdcDirectionType DIRECTION, 
        TThostFtdcVolumeType VOLUME, TThostFtdcPriceType LIMIT_PRICE, TThostFtdcOffsetFlagType OFFSET_FLAG);
	///报单操作请求
	void ReqOrderAction(CThostFtdcOrderField *pOrder);
	// 是否我的报单回报
	bool IsMyOrder(CThostFtdcOrderField *pOrder);

	// 跟单操作
	void rspTradingAciton();
	void FollowRtnTrade(CThostFtdcTradeField tradeField);
    void ProcessTradeEvent(CThostFtdcTradeField tradeField);

	// 下面的不管
	///请求查询合约
	void ReqQryInstrument(TThostFtdcInstrumentIDType instrument_id);
	///请求查询投资者持仓
	void ReqQryInvestorPosition(TThostFtdcInstrumentIDType instrument_id);

	///执行宣告录入请求
	void ReqExecOrderInsert(TThostFtdcInstrumentIDType INSTRUMENT_ID);
	///执行宣告操作请求
	void ReqExecOrderAction(CThostFtdcExecOrderField *pExecOrder);
	// 是否我的执行宣告回报
	bool IsMyExecOrder(CThostFtdcExecOrderField *pExecOrder);

	///询价录入请求
	void ReqForQuoteInsert(TThostFtdcInstrumentIDType INSTRUMENT_ID);
	///报价录入请求
	void ReqQuoteInsert(TThostFtdcInstrumentIDType INSTRUMENT_ID, TThostFtdcPriceType LIMIT_PRICE);
	///报价操作请求
	void ReqQuoteAction(CThostFtdcQuoteField *pQuote);
	// 是否我的报价
	bool IsMyQuote(CThostFtdcQuoteField *pQuote);

};
