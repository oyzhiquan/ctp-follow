#include "ThostTraderApi\ThostFtdcTraderApi.h"
#include "include\TraderSpi.h"
#include <QtCore>
#include <map>
#include <string>
using namespace std;

typedef struct
{
    char inverstorID[13];
    char password[41];
    char brokerID[11];
    char brokerName[20];
    char tdFrontAddr[101];
    int direct;
    float ratio;
} Account;

typedef struct
{
	int direct;
	float ratio;
} FollowStrategy;

typedef struct
{
    int id;
    int followType;
    int actionSec;
    int priceType;
    int priceJump;
    int actionTimes;
    int finalType;
} Strategy;

class MainTrader: public QObject
{
	Q_OBJECT

public:
    MainTrader(Account &account);
	~MainTrader();
	void SetThread(QThread * mainThread);
    void AddFollowStrategy(const char* investorID, FollowStrategy &followStrategy);

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

	MainTraderSpi * m_pTraderSpi;
	CThostFtdcTraderApi* m_pTraderApi;

	QThread * m_pThread;
    map<string, FollowStrategy> m_followStrategys;
    vector<Strategy> m_orderStrategys;

private:
	bool IsFlowControl(int iResult);
    void LoadStrategy();

signals:
	void TraderStatusUpdated(QString message);
	void TraderBalanceUpdated(double balance, double closeProfit, double positionProfit);
    void EventTableUpdated(QString message);
    void TraderLogined();

public slots:
	void ReqConnect();
    void ReqDisconnect();
	///用户登录请求
	void ReqUserLogin();
	void RspUserLogin(int front_id ,int session_id, int iNextOrderRef);
	///投资者结算结果确认
	void ReqSettlementInfoConfirm();
	///请求查询资金账户
	void ReqQryTradingAccount();
	void RspQryTradingAccount(double balance, double closeProfit, double positionProfit);


	///报单录入请求
	void ReqOrderInsert(TThostFtdcInstrumentIDType INSTRUMENT_ID, TThostFtdcDirectionType DIRECTION, 
        TThostFtdcVolumeType VOLUME, TThostFtdcPriceType LIMIT_PRICE, TThostFtdcOffsetFlagType OFFSET_FLAG);
	///报单操作请求
	void ReqOrderAction(CThostFtdcOrderField *pOrder);
	// 是否我的报单回报
	bool IsMyOrder(CThostFtdcOrderField *pOrder);

	// 跟单操作
	void RspTradingAciton();
	void FollowRtnTrade(CThostFtdcTradeField tradeField);
    void ProcessTradeEvent(CThostFtdcTradeField tradeField);
};
