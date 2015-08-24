#pragma once
#include "ThostTraderApi\ThostFtdcTraderApi.h"
#include <QtCore>

class MainTraderSpi : public QObject, public CThostFtdcTraderSpi
{
	Q_OBJECT

signals:
	void FrontConnected();
	void UserLogined(int front_id ,int session_id, int iNextOrderRef);
	void SettlementInfoConfirmed();
	void TraderBalanceUpdated(double balance, double closeProfit, double positionProfit);
	void RtnTradeEvent(CThostFtdcTradeField tradeField);

public:
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected();
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	virtual void OnFrontDisconnected(int nReason);

	///登录请求响应
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,	
        CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///投资者结算结果确认响应
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, 
        CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///请求查询资金账户响应
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, 
        CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///报单录入请求响应
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, 
        CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///报单操作请求响应
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, 
        CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	///报单通知
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
	///成交通知
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);

	///错误应答
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	virtual void OnHeartBeatWarning(int nTimeLapse);

private:
	// 是否收到成功的响应
	bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
	// 是否正在交易的报单
	bool IsTradingOrder(CThostFtdcOrderField *pOrder);
};


class FollowTraderSpi: public QObject, public CThostFtdcTraderSpi
{
    Q_OBJECT

public:
    FollowTraderSpi();
    ~FollowTraderSpi();

private:
    int m_index;                                  // 编号
    TThostFtdcAddressType m_FRONT_ADDR;     	  // 前置地址
    TThostFtdcBrokerIDType	m_BROKER_ID;       	  // 经纪公司代码
    TThostFtdcInvestorIDType m_INVESTOR_ID;		  // 投资者代码
    TThostFtdcPasswordType  m_PASSWORD;			  // 用户密码 
    int m_iRequestID;
    int m_iNextOrderRef;
    // 会话参数
    TThostFtdcFrontIDType	m_FRONT_ID;		//前置编号
    TThostFtdcSessionIDType	m_SESSION_ID;	//会话编号

    CThostFtdcTraderApi* m_pTraderApi;

signals:
    void TraderBalanceUpdated(int index, double balance, double closeProfit, double positionProfit);
    void TraderStatusUpdated(int index, QString message);
    void EventTableUpdated(QString message);
    void TraderLogined(int index);
    void RtnTradeEvent(CThostFtdcTradeField tradeField);
    void RspErrorInfo();

public slots:
    void ReqConnect();

public:
    void Init(int index, const char* frontAddr, const char* brokerID,
        const char* investorID, const char* password);

    // 用户登录请求
    void ReqUserLogin();
    ///投资者结算结果确认
    void ReqSettlementInfoConfirm();
    ///请求查询资金账户
    void ReqQryTradingAccount();

    ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    virtual void OnFrontConnected();
    ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
    virtual void OnFrontDisconnected(int nReason);

    ///登录请求响应
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,	
        CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    ///投资者结算结果确认响应
    virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, 
        CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    ///请求查询资金账户响应
    virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, 
        CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///报单通知
    virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
    ///成交通知
    virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);


    ///错误应答
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///心跳超时警告。当长时间未收到报文时，该方法被调用。
    virtual void OnHeartBeatWarning(int nTimeLapse);

private:
    // 是否收到成功的响应
    bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
    // 是否正在交易的报单
    bool IsTradingOrder(CThostFtdcOrderField *pOrder);
    bool IsFlowControl(int iResult);
};