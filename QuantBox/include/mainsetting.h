#include <QtWidgets\Qdialog>
#include <QtSql>
#include "ui_mainsetting.h"

class MainSetting:public QDialog
{
	Q_OBJECT

public:
	MainSetting(QWidget *parent = 0);
	~MainSetting();

public slots:
    void saveBtnClicked();
    void BrokerNameselected(QString brokerName);

private:
    void SetUiValue();

private:
	Ui::MainSettingClass ui;
    QSqlDatabase db;
};
