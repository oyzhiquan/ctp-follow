#include "include\followsetting.h"
#include <QMessageBox>

FollowSetting::FollowSetting(QWidget *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	db = QSqlDatabase::database();
	if(!db.open())
	{
		qDebug() << "db open error" << endl;
	}

	QHeaderView *headerView = ui.followView->horizontalHeader();
	headerView->resizeSection(0, 120);
	headerView->resizeSection(1, 138);
	headerView->resizeSection(2, 110);
    headerView->resizeSection(3, 110);
    headerView->resizeSection(4, 0);
	LoadDate();
    LoadBroker();
}

FollowSetting::~FollowSetting()
{
	db.close();
}

void FollowSetting::LoadDate()
{
	QTableWidget* table = ui.followView;
	table->setRowCount(0);
	QSqlQuery query;
	int row = 0;
	query.exec("select inverst_id, broker_name, direct, ratio, password from follow order by id");
	while(query.next())
	{
		table->insertRow(row);
		table->setItem(row, 0, new QTableWidgetItem(QString(query.value(0).toByteArray().data())));
		table->setItem(row, 1, new QTableWidgetItem(QString(query.value(1).toByteArray().data())));
		if(query.value(2).toInt() == 0)
			table->setItem(row, 2, new QTableWidgetItem(QString::fromLocal8Bit("正向跟单")));
		else
			table->setItem(row, 2, new QTableWidgetItem(QString::fromLocal8Bit("反向跟单")));
		table->setItem(row, 3, new QTableWidgetItem(QString::number(query.value(3).toFloat(), 'f', 1)));
		table->setItem(row, 4, new QTableWidgetItem(QString(query.value(4).toByteArray().data())));
		row++;
	}
}

void FollowSetting::LoadBroker()
{
    QSqlQuery query;
    query.exec("select distinct broker_name from broker order by id");
    while(query.next())
    {
        ui.followBrokerName->addItem(QString(query.value(0).toByteArray().data()));
    }
}

void FollowSetting::followCellClicked(int row, int col)
{
	QTableWidget* table = ui.followView;
	ui.followInverstID->setText(table->item(row, 0)->text());
	ui.followBrokerName->setCurrentText(table->item(row, 1)->text());
	ui.followDirect->setCurrentText(table->item(row, 2)->text());
	ui.followRatio->setText(table->item(row, 3)->text());
	ui.followPassword->setText(table->item(row, 4)->text());
}

void FollowSetting::BrokerNameselected(QString brokerName)
{
    QSqlQuery query;
    QString sql = "select broker_id, td_front_addr from broker where broker_name=? ";
    query.prepare(sql);
    query.addBindValue(ui.followBrokerName->currentText());
    query.exec();
    if(query.next())
    {
        ui.followBrokerID->setText(QString(query.value(0).toByteArray().data()));
        ui.followTdFrontAddr->setText(QString(query.value(1).toByteArray().data()));
    }
}

void FollowSetting::insertBtnClicked()
{
	QSqlQuery query;
	QString sql = "insert into follow(inverst_id, password, broker_name, direct, ratio) \
				  values(?, ?, ?, ?, ?)";
	query.prepare(sql);
	query.addBindValue(ui.followInverstID->text());
	query.addBindValue(ui.followPassword->text());
	query.addBindValue(ui.followBrokerName->currentText());
	query.addBindValue(ui.followDirect->currentIndex());
	query.addBindValue(ui.followRatio->text().toFloat());
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

void FollowSetting::deleteBtnClicked()
{
	QSqlQuery query;
	QString sql = "delete from follow where inverst_id = ?";
	query.prepare(sql);
	query.addBindValue(ui.followInverstID->text());
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

void FollowSetting::updateBtnClicked()
{
	QSqlQuery query;
	QString sql = "update follow set broker_name=?, direct=?, ratio=?, password=? where inverst_id=?";
	query.prepare(sql);
	query.addBindValue(ui.followBrokerName->currentText());
	query.addBindValue(ui.followDirect->currentIndex());
	query.addBindValue( ui.followRatio->text().toFloat());
	query.addBindValue(ui.followPassword->text());
	query.addBindValue(ui.followInverstID->text());
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