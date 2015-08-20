
#include <QtWidgets\Qdialog>
#include "ui_mainsetting.h"

class MainSetting:public QDialog
{
	Q_OBJECT

public:
	MainSetting(QWidget *parent = 0);
	~MainSetting();

private:
	Ui::MainSettingClass ui;

};
