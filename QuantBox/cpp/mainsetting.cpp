#include "include\mainsetting.h"
#include <QMessageBox>

MainSetting::MainSetting(QWidget *parent)
	:QDialog(parent)
{
    ui.setupUi(this);
    db = QSqlDatabase::database();
    if(!db.open())
    {
        qDebug() << "db open error" << endl;
    }
    SetUiValue();
}

MainSetting::~MainSetting()
{
    db.close();
}

void MainSetting::SetUiValue()
{
    QSqlQuery query;
    query.exec("select distinct broker_name from broker order by id");
    while(query.next())
    {
        ui.brokerName->addItem(QString(query.value(0).toByteArray().data()));
    }
    query.exec("select inverst_id, password, broker_name from account where id=1");
    if(query.next())
    {
        ui.inverstID->setText(QString(query.value(0).toByteArray().data()));
        ui.password->setText(QString(query.value(1).toByteArray().data()));
        ui.brokerName->setCurrentText(QString(query.value(2).toByteArray().data()));
    }
}

void MainSetting::saveBtnClicked()
{
    QSqlQuery query;
    QString sql = "update account set inverst_id=?, password=?, broker_name=? where id=1";
    query.prepare(sql);
    query.addBindValue(ui.inverstID->text());
    query.addBindValue(ui.password->text());
    query.addBindValue(ui.brokerName->currentText());
    if(query.exec() && query.numRowsAffected() > 0)
    {
        QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("更新成功！"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("更新失败！"), QMessageBox::Ok);
    }
}

void MainSetting::BrokerNameselected(QString brokerName)
{
    QSqlQuery query;
    QString sql = "select broker_id, td_front_addr from broker where broker_name=? ";
    query.prepare(sql);
    query.addBindValue(ui.brokerName->currentText());
    query.exec();
    if(query.next())
    {
        ui.brokerID->setText(QString(query.value(0).toByteArray().data()));
        ui.frontAddr->setText(QString(query.value(1).toByteArray().data()));
    }
}