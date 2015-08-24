#include <QtWidgets\Qdialog>
#include <QtSql>
#include "ui_strategysetting.h"

class StrategySetting:public QDialog
{
	Q_OBJECT

public:
	StrategySetting(QWidget *parent = 0);
	~StrategySetting();

private:
	void LoadDate();

private:
	Ui::StrategySettingClass ui;

	QSqlDatabase db;

private slots:
	void saveBtnClicked();
};
