#include "include\brokermanage.h"
#include <QMessageBox>

BrokerManage::BrokerManage(QWidget *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	db = QSqlDatabase::database();
	if(!db.open())
	{
		qDebug() << "db open error" << endl;
	}
	QHeaderView *headerView = ui.BrokerTable->horizontalHeader();
	headerView->resizeSection(0, 100);
	headerView->resizeSection(1, 68);
	headerView->resizeSection(2, 274);
	LoadDate();
}

BrokerManage::~BrokerManage()
{
	db.close();
}

void BrokerManage::LoadDate()
{
	QTableWidget* table = ui.BrokerTable;
	table->setRowCount(0);
	QSqlQuery query;
	int row = 0;
	query.exec("select broker_name, broker_id, td_front_addr from broker order by id");
	while(query.next())
	{
		table->insertRow(row);
		table->setItem(row, 0, new QTableWidgetItem(QString(query.value(0).toByteArray().data())));
		table->setItem(row, 1, new QTableWidgetItem(QString(query.value(1).toByteArray().data())));
		table->setItem(row, 2, new QTableWidgetItem(QString(query.value(2).toByteArray().data())));
		row++;
	}
    ui.brokerName->clear();
    ui.brokerID->clear();
    ui.frontAddr->clear();
}

void BrokerManage::CellClicked(int row, int col)
{
	QTableWidget* table = ui.BrokerTable;
	ui.brokerName->setText(table->item(row, 0)->text());
	ui.brokerID->setText(table->item(row, 1)->text());
	ui.frontAddr->setText(table->item(row, 2)->text());
}

void BrokerManage::insertBtnClicked()
{
	QSqlQuery query;
	QString sql = "insert into broker(broker_name, broker_id, td_front_addr) values(?, ?, ?)";
    query.prepare(sql);
    query.addBindValue(ui.brokerName->text());
	query.addBindValue(ui.brokerID->text());
	query.addBindValue(ui.frontAddr->text());
	if(query.exec() && query.numRowsAffected() > 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("增加成功！"), QMessageBox::Ok);
		LoadDate();
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("增加失败！"), QMessageBox::Ok);
	}
}

void BrokerManage::deleteBtnClicked()
{
	QSqlQuery query;
	QString sql = "delete from broker where broker_name = ?";
	query.prepare(sql);
	query.addBindValue(ui.brokerName->text());
	if(query.exec() && query.numRowsAffected() > 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("删除成功！"), QMessageBox::Ok);
		LoadDate();
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("删除失败！"), QMessageBox::Ok);
	}
}

void BrokerManage::updateBtnClicked()
{
	QSqlQuery query;
	QString sql = "update broker set broker_id=?, td_front_addr=? where broker_name=?";
    query.prepare(sql);
    query.addBindValue(ui.brokerID->text());
    query.addBindValue(ui.frontAddr->text());
    query.addBindValue(ui.brokerName->text());
	if(query.exec() && query.numRowsAffected() > 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("更新成功！"), QMessageBox::Ok);
		LoadDate();
	}
	else
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("更新失败！"), QMessageBox::Ok);
	}
}