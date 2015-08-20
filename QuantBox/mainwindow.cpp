#include "mainwindow.h"
#include "include\mainsetting.h"
#include "include\followsetting.h"
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
	if(m_eventModel != NULL)
		delete m_eventModel;
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
	m_eventModel = new QStandardItemModel();
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
		query.exec("select inverst_id, password, broker_id, broker_name, td_front_addr from account where id = 1");
		if(query.next())
		{
			strcpy(m_mainAccount.inverst_id, query.value(0).toByteArray().data());
			strcpy(m_mainAccount.password, query.value(1).toByteArray().data());
			strcpy(m_mainAccount.broker_id, query.value(2).toByteArray().data());
			strcpy(m_mainAccount.broker_name, query.value(3).toByteArray().data());
			strcpy(m_mainAccount.td_front_addr, query.value(4).toByteArray().data());
		}
		db.close();
		ui.mainUsername->setText(QString(m_mainAccount.inverst_id));
		ui.mainBrokerName->setText(QString::fromLocal8Bit(m_mainAccount.broker_name));
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
		query.exec("select inverst_id, password, broker_id, broker_name, td_front_addr, direct, ratio from follow order by id");
		Account temp;
		while(query.next())
		{
			strcpy(temp.inverst_id, query.value(0).toByteArray().data());
			strcpy(temp.password, query.value(1).toByteArray().data());
			strcpy(temp.broker_id, query.value(2).toByteArray().data());
			strcpy(temp.broker_name, query.value(3).toByteArray().data());
			strcpy(temp.td_front_addr, query.value(4).toByteArray().data());
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
		table->setItem(i, 1, new QTableWidgetItem(QString(m_followAccount[i].inverst_id)));
		table->setItem(i, 2, new QTableWidgetItem(QString(m_followAccount[i].broker_name)));
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
	m_pMainTrader = new CTrader(-1, m_mainAccount);
	QThread * thread = new QThread();
	// 线程结束时自动删除指针
    QObject::connect(thread, &QThread::finished, m_pMainTrader, &CTrader::deleteLater);
    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);
	// 线程启动时自动发送登录信号
    QObject::connect(thread, &QThread::started, m_pMainTrader, &CTrader::ReqConnect);
    // 主账号登录后，样本账号开始登录
    QObject::connect(m_pMainTrader, &CTrader::traderLogined, this, &MainWindow::followTraderLogin);
    QObject::connect(this, &MainWindow::traderLogout, m_pMainTrader, &CTrader::ReqLogout);
    // 界面更新信号
	QObject::connect(m_pMainTrader, &CTrader::traderStatusUpdated, this, &MainWindow::updateStatus);
    QObject::connect(m_pMainTrader, &CTrader::traderBalanceUpdated, this, &MainWindow::updateBalance);
    QObject::connect(m_pMainTrader, &CTrader::eventTableUpdated, this, &MainWindow::insertEventTable);
	
	m_pMainTrader->SetThread(thread);
	thread->start();
	updateStatus(-1, QString::fromLocal8Bit("启动线程"));
}

void MainWindow::followTraderLogin()
{
	for(int index=0; index<m_followAccount.size(); index++)
	{
		CTrader* pFollowTrader = new CTrader(index, m_followAccount[index]);
		QThread* thread = new QThread();
		// 线程结束时自动删除指针
        QObject::connect(thread, &QThread::finished, pFollowTrader, &CTrader::deleteLater);
        QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);
		// 线程启动时自动发送登录信号
        QObject::connect(thread, &QThread::started, pFollowTrader, &CTrader::ReqConnect);
        // 跟踪账号登录后，开始关联交易
        QObject::connect(pFollowTrader, &CTrader::traderLogined, this, &MainWindow::connectFollow2Main);
        QObject::connect(this, &MainWindow::traderLogout, pFollowTrader, &CTrader::ReqLogout);
        // 界面更新信号
		QObject::connect(pFollowTrader, &CTrader::traderStatusUpdated, this, &MainWindow::updateStatus);
        QObject::connect(pFollowTrader, &CTrader::traderBalanceUpdated, this, &MainWindow::updateBalance);
        QObject::connect(pFollowTrader, &CTrader::eventTableUpdated, this, &MainWindow::insertEventTable);

		pFollowTrader->SetThread(thread);
		thread->start();
		updateStatus(index, QString::fromLocal8Bit("启动线程"));
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
    emit traderLogout();
    m_pFollowTrader.clear();
    ui.beginFollowBtn->setEnabled(true);
    ui.stopFollowBtn->setEnabled(false);
}

void MainWindow::connectFollow2Main(int index)
{
    CTrader* followTrader = m_pFollowTrader[index];
    QObject::connect(followTrader, &CTrader::RtnTradeEvent, m_pMainTrader, &CTrader::FollowRtnTrade);
    insertEventTable(QString::fromLocal8Bit("主账号%1开始监听样本账号%2")
        .arg(m_mainAccount.inverst_id, m_followAccount[index].inverst_id));
}

void MainWindow::updateStatus(int index, QString message)
{
	if(index == -1)
    {
		ui.mainStatus->setText(message);
	}
    else
    {
        ui.followView->setItem(index, 5, new QTableWidgetItem(message));
	}
}

void MainWindow::updateBalance(int index, double balance, double positionProfit, double closeProfit)
{
	if(index == -1)
	{
		ui.mainBalance->setText(QString::number(balance, 'f', 2));
		ui.mainPositionProfit->setText(QString::number(positionProfit, 'f', 2));
		ui.mainCloseProfit->setText(QString::number(closeProfit, 'f', 2));
	}
	else
	{
		ui.followView->setItem(index, 6, new QTableWidgetItem(QString::number(balance, 'f', 2)));
		ui.followView->setItem(index, 7, new QTableWidgetItem(QString::number(positionProfit, 'f', 2)));
		ui.followView->setItem(index, 8, new QTableWidgetItem(QString::number(closeProfit, 'f', 2)));
	}
}

void MainWindow::insertEventTable(QString message)
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