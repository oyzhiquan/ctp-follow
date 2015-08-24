
#include <QtWidgets\Qdialog>
#include <QtSql>
#include "ui_followsetting.h"

class FollowSetting:public QDialog
{
	Q_OBJECT

public:
	FollowSetting(QWidget *parent = 0);
	~FollowSetting();

private:
	void LoadDate();
    void LoadBroker();

private:
	Ui::FollowSettingClass ui;
	
	QSqlDatabase db;

private slots:
	void followCellClicked(int row, int col);
    void BrokerNameselected(QString brokerName);

	void insertBtnClicked();
	void deleteBtnClicked();
	void updateBtnClicked();

};
