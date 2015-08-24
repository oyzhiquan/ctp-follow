
#include <QtWidgets\Qdialog>
#include <QtSql>
#include "ui_brokermanage.h"

class BrokerManage:public QDialog
{
	Q_OBJECT

public:
	BrokerManage(QWidget *parent = 0);
	~BrokerManage();

private:
	void LoadDate();

private:
	Ui::BrokerManageClass ui;
	QSqlDatabase db;

private slots:
	void CellClicked(int row, int col);

	void insertBtnClicked();
	void deleteBtnClicked();
	void updateBtnClicked();

};
