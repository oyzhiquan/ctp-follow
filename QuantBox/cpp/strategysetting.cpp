#include "include\strategysetting.h"
#include <QMessageBox>

StrategySetting::StrategySetting(QWidget *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	db = QSqlDatabase::database();
	if(!db.open())
	{
		qDebug() << "db open error" << endl;
	}
	LoadDate();
}

StrategySetting::~StrategySetting()
{
	db.close();
}

void StrategySetting::LoadDate()
{
	QSqlQuery query;
	query.exec("select follow_type, action_sec, price_type, price_jump, action_times, final_type from strategy order by id");
    query.next();
    ui.followType->setCurrentIndex(query.value(0).toInt());
    ui.openActionSec->setValue(query.value(1).toInt());
    ui.openPriceType->setCurrentIndex(query.value(2).toInt());
    ui.openJump->setValue(query.value(3).toInt());
    ui.openTimes->setValue(query.value(4).toInt());
    ui.openFinal->setCurrentIndex(query.value(5).toInt());
    query.next();
    ui.closeActionSec->setValue(query.value(1).toInt());
    ui.closePriceType->setCurrentIndex(query.value(2).toInt());
    ui.closeJump->setValue(query.value(3).toInt());
    ui.closeTimes->setValue(query.value(4).toInt());
    ui.closeFinal->setCurrentIndex(query.value(5).toInt());
}


void StrategySetting::saveBtnClicked()
{
	QSqlQuery query;
	QString sql = "update strategy set follow_type=?, action_sec=?, price_type=?, \
				  price_jump=?, action_times=?, final_type=? where id=?";
	query.prepare(sql);
	query.addBindValue(ui.followType->currentIndex());
	query.addBindValue(ui.openActionSec->value());
	query.addBindValue(ui.openPriceType->currentText());
	query.addBindValue(ui.openJump->value());
	query.addBindValue(ui.openTimes->value());
	query.addBindValue(ui.openFinal->currentIndex());
	query.addBindValue(1);
	if(!query.exec() || query.numRowsAffected() == 0)
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("保存失败！"), QMessageBox::Ok);
        return;
    }
    query.prepare(sql);
    query.addBindValue(ui.followType->currentIndex());
    query.addBindValue(ui.closeActionSec->value());
    query.addBindValue(ui.closePriceType->currentText());
    query.addBindValue(ui.closeJump->value());
    query.addBindValue(ui.closeTimes->value());
    query.addBindValue(ui.closeFinal->currentIndex());
    query.addBindValue(2);
    if(!query.exec() || query.numRowsAffected() == 0)
    {
        QMessageBox::critical(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("保存失败！"), QMessageBox::Ok);
        return;
    }
    QMessageBox::information(this, QString::fromLocal8Bit("消息"), QString::fromLocal8Bit("更新成功！"), QMessageBox::Ok);
}