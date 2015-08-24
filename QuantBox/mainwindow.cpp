#include "mainwindow.h"
#include "include\mainsetting.h"
#include "include\followsetting.h"
#include "include\brokermanage.h"
#include "include\strategysetting.h"
#include <QCheckBox>
#include <iostream>
using namespace std;

Q_DECLARE_METATYPE(CThostFtdcTradeField);

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    // 设置菜单事件
	QObject::connect(ui.mainSetting, &QAction::triggered, this, &MainWindow::mainSettingClicked);
    QObject::connect(ui.followSetting, &QAction::triggered, this, &MainWindow::followSettingClicked);
    QObject::connect(ui.brokerManage, &QAction::triggered, this, &MainWindow::brokerManageClicked);
    QObject::connect(ui.strategySetting, &QAction::triggered, this, &MainWindow::strategySetttingClicked);

	setupFollowTable();
	setupEventTable();

	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(QCoreApplication::applicationDirPath() + "/data.db");

	loadMainAccount();
	loadFollowAccount();

    qRegisterMetaType<CThostFtdcTradeField>("CThostFtdcTradeField");
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupFollowTable()
{
	QHeaderView *headerView = ui.followView->horizontalHeader();
	headerView->resizeSection(0, 48);
	headerView->resizeSection(1, 80);
	headerView->resizeSection(2, 100);
	headerView->resizeSection(3, 80);
	headerView->resizeSection(4, 80);
	headerView->resizeSection(5, 90);
	headerView->resizeSection(6, 100);
	headerView->resizeSection(7, 90);
	headerView->resizeSection(8, 90);
}

void MainWindow::setupEventTable()
{
	QTableView * table = ui.eventTable;
	m_eventModel = new QStandardItemModel(this);
    m_eventModel->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("发生时间")));
    m_eventModel->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("事件内容")));
	table->setModel(m_eventModel);
	table->setColumnWidth(0, 100);
	table->setColumnWidth(1, 641);
}

void MainWindow::loadMainAccount()
{
	if(db.open())
    {
		QSqlQuery query;
        query.exec("select inverst_id, password, b.broker_id, b.broker_name, b.td_front_addr \
                   from account a left join broker b on a.broker_name = b.broker_name where a.id = 1");
		if(query.next())
		{
			strcpy(m_mainAccount.inverstorID, query.value(0).toByteArray().data());
			strcpy(m_mainAccount.password, query.value(1).toByteArray().data());
			strcpy(m_mainAccount.brokerID, query.value(2).toByteArray().data());
			strcpy(m_mainAccount.brokerName, query.value(3).toByteArray().data());
			strcpy(m_mainAccount.tdFrontAddr, query.value(4).toByteArray().data());
		}
		db.close();
		ui.mainUsername->setText(QString(m_mainAccount.inverstorID));
		ui.mainBrokerName->setText(QString(m_mainAccount.brokerName));
    }
	else
	{
		cout << "db open error" << endl;
	}
}

void MainWindow::loadFollowAccount()
{
	m_followAccount.clear();
	if(db.open())
    {
		QSqlQuery query;
        query.exec("select inverst_id, password, b.broker_id, b.broker_name, b.td_front_addr, direct, ratio \
                   from follow a left join broker b on a.broker_name = b.broker_name order by a.id");
		Account temp;
		while(query.next())
		{
			strcpy(temp.inverstorID, query.value(0).toByteArray().data());
			strcpy(temp.password, query.value(1).toByteArray().data());
			strcpy(temp.brokerID, query.value(2).toByteArray().data());
			strcpy(temp.brokerName, query.value(3).toByteArray().data());
			strcpy(temp.tdFrontAddr, query.value(4).toByteArray().data());
			temp.direct = query.value(5).toInt();
			temp.ratio = query.value(6).toFloat();
			m_followAccount.push_back(temp);
		}
		db.close();
    }
	else
	{
		cout << "db open error" << endl;
	}
	QTableWidget* table = ui.followView;
	table->setRowCount(m_followAccount.size());
	for(int i=0; i < m_followAccount.size(); i++)
	{
		table->setItem(i, 0, new QTableWidgetItem(QString::number(i+1)));
		table->setItem(i, 1, new QTableWidgetItem(QString(m_followAccount[i].inverstorID)));
		table->setItem(i, 2, new QTableWidgetItem(QString(m_followAccount[i].brokerName)));
		if(m_followAccount[i].direct == 0)
			table->setItem(i, 3, new QTableWidgetItem(QString::fromLocal8Bit("正向跟单")));
		else
			table->setItem(i, 3, new QTableWidgetItem(QString::fromLocal8Bit("反向跟单")));
		table->setItem(i, 4, new QTableWidgetItem(QString::number(m_followAccount[i].ratio, 'f', 1)));
		table->setItem(i, 5, new QTableWidgetItem(QString::fromLocal8Bit("未登录")));
		table->setItem(i, 6, new QTableWidgetItem("0.00"));
		table->setItem(i, 7, new QTableWidgetItem("0.00"));
		table->setItem(i, 8, new QTableWidgetItem("0.00"));
	}
}

void MainWindow::mainTraderLogin()
{
	m_pMainTrader = new MainTrader(m_mainAccount);
	QThread * pMainThread = new QThread();
    FollowStrategy strategy;
    for (int i=0; i < m_followAccount.size(); i++)
    {
        strategy.direct = m_followAccount[i].direct;
        strategy.ratio = m_followAccount[i].ratio;
        m_pMainTrader->AddFollowStrategy(m_followAccount[i].inverstorID, strategy);
    }
	// 线程结束时自动删除指针
    QObject::connect(pMainThread, &QThread::finished, m_pMainTrader, &MainTrader::deleteLater);
    QObject::connect(pMainThread, &QThread::finished, pMainThread, &QThread::deleteLater);
	// 线程启动时自动发送登录信号
    QObject::connect(pMainThread, &QThread::started, m_pMainTrader, &MainTrader::ReqConnect);
    // 主账号登录后，样本账号开始登录
    QObject::connect(m_pMainTrader, &MainTrader::TraderLogined, this, &MainWindow::FollowTraderLogin);
    // 发出退出登录信号主账号退出
    QObject::connect(this, &MainWindow::TraderLogout, m_pMainTrader, &MainTrader::ReqDisconnect);
    // 界面更新信号
	QObject::connect(m_pMainTrader, &MainTrader::TraderStatusUpdated, this, &MainWindow::UpdateMainStatus);
    QObject::connect(m_pMainTrader, &MainTrader::TraderBalanceUpdated, this, &MainWindow::UpdateMainBalance);
    QObject::connect(m_pMainTrader, &MainTrader::EventTableUpdated, this, &MainWindow::InsertEventTable);
	
	m_pMainTrader->SetThread(pMainThread);
	pMainThread->start();
	UpdateMainStatus(QString::fromLocal8Bit("启动线程"));
}

void MainWindow::FollowTraderLogin()
{
	for(int index=0; index<m_followAccount.size(); index++)
	{
		FollowTraderSpi* pFollowTrader = new FollowTraderSpi();
        pFollowTrader->Init(index, m_followAccount[index].tdFrontAddr, m_followAccount[index].brokerID,
            m_followAccount[index].inverstorID, m_followAccount[index].password);
		// 发出退出登录信号自动删除指针
        QObject::connect(this, &MainWindow::TraderLogout, pFollowTrader, &FollowTraderSpi::deleteLater);
        // 跟踪账号登录后，开始关联交易
        QObject::connect(pFollowTrader, &FollowTraderSpi::TraderLogined, this, &MainWindow::connectFollow2Main);
        // 界面更新信号
		QObject::connect(pFollowTrader, &FollowTraderSpi::TraderStatusUpdated, this, &MainWindow::UpdateFollowStatus);
        QObject::connect(pFollowTrader, &FollowTraderSpi::TraderBalanceUpdated, this, &MainWindow::UpdateFollowBalance);
        QObject::connect(pFollowTrader, &FollowTraderSpi::EventTableUpdated, this, &MainWindow::InsertEventTable);

		pFollowTrader->ReqConnect();
		UpdateFollowStatus(index, QString::fromLocal8Bit("启动线程"));
		m_pFollowTrader.push_back(pFollowTrader);
	}
}


void MainWindow::beginFollowBtnClicked()
{
    mainTraderLogin();
    ui.beginFollowBtn->setEnabled(false);
    ui.stopFollowBtn->setEnabled(true);
}

void MainWindow::stopFollowBtnClicked()
{
    emit TraderLogout();
    m_pFollowTrader.clear();
    ui.beginFollowBtn->setEnabled(true);
    ui.stopFollowBtn->setEnabled(false);
}

void MainWindow::connectFollow2Main(int index)
{
    FollowTraderSpi* followTrader = m_pFollowTrader[index];
    QObject::connect(followTrader, &FollowTraderSpi::RtnTradeEvent, m_pMainTrader, &MainTrader::FollowRtnTrade);
    InsertEventTable(QString::fromLocal8Bit("主账号%1开始监听样本账号%2")
        .arg(m_mainAccount.inverstorID, m_followAccount[index].inverstorID));
}

void MainWindow::UpdateMainStatus(QString message)
{
    ui.mainStatus->setText(message);
}   

void MainWindow::UpdateFollowStatus(int index, QString message)
{
    ui.followView->setItem(index, 5, new QTableWidgetItem(message));
}

void MainWindow::UpdateMainBalance(double balance, double positionProfit, double closeProfit)
{
    ui.mainBalance->setText(QString::number(balance, 'f', 2));
    ui.mainPositionProfit->setText(QString::number(positionProfit, 'f', 2));
    ui.mainCloseProfit->setText(QString::number(closeProfit, 'f', 2));
}

void MainWindow::UpdateFollowBalance(int index, double balance, double positionProfit, double closeProfit)
{
    ui.followView->setItem(index, 6, new QTableWidgetItem(QString::number(balance, 'f', 2)));
	ui.followView->setItem(index, 7, new QTableWidgetItem(QString::number(positionProfit, 'f', 2)));
    ui.followView->setItem(index, 8, new QTableWidgetItem(QString::number(closeProfit, 'f', 2)));
}

void MainWindow::InsertEventTable(QString message)
{
	int row = m_eventModel->rowCount();
    QString current_time = QDateTime::currentDateTime().toString("hh:mm:ss:zzz");
	m_eventModel->setItem(row, 0, new QStandardItem(current_time));
	m_eventModel->setItem(row, 1, new QStandardItem(message));
}


void MainWindow::mainSettingClicked()
{
    MainSetting mainSetting(this);
    QObject::connect(&mainSetting, &FollowSetting::destroyed, this, &MainWindow::loadMainAccount); 
    mainSetting.exec();
}

void MainWindow::followSettingClicked()
{
    FollowSetting followSetting(this);
    QObject::connect(&followSetting, &FollowSetting::destroyed, this, &MainWindow::loadFollowAccount); 
    followSetting.exec();
}

void MainWindow::brokerManageClicked()
{
    BrokerManage brokerManage(this);
    brokerManage.exec();
}

void MainWindow::strategySetttingClicked()
{
    StrategySetting strategySetting(this);
    strategySetting.exec();
}