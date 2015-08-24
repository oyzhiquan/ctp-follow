/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *mainSetting;
    QAction *followSetting;
    QAction *strategySetting;
    QAction *brokerManage;
    QWidget *centralWidget;
    QGroupBox *MainBox;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_10;
    QLineEdit *mainStatus;
    QLineEdit *mainBalance;
    QLineEdit *mainPositionProfit;
    QLineEdit *mainCloseProfit;
    QPushButton *beginFollowBtn;
    QPushButton *stopFollowBtn;
    QLabel *label;
    QLineEdit *mainUsername;
    QLabel *label_3;
    QLineEdit *mainBrokerName;
    QGroupBox *FollowBox;
    QTableWidget *followView;
    QGroupBox *ReportBox;
    QTableView *eventTable;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(800, 600);
        mainSetting = new QAction(MainWindowClass);
        mainSetting->setObjectName(QStringLiteral("mainSetting"));
        followSetting = new QAction(MainWindowClass);
        followSetting->setObjectName(QStringLiteral("followSetting"));
        strategySetting = new QAction(MainWindowClass);
        strategySetting->setObjectName(QStringLiteral("strategySetting"));
        brokerManage = new QAction(MainWindowClass);
        brokerManage->setObjectName(QStringLiteral("brokerManage"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainBox = new QGroupBox(centralWidget);
        MainBox->setObjectName(QStringLiteral("MainBox"));
        MainBox->setGeometry(QRect(10, 10, 780, 80));
        label_5 = new QLabel(MainBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(405, 20, 50, 20));
        label_6 = new QLabel(MainBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(15, 50, 50, 20));
        label_8 = new QLabel(MainBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(210, 50, 50, 20));
        label_10 = new QLabel(MainBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(405, 50, 50, 20));
        mainStatus = new QLineEdit(MainBox);
        mainStatus->setObjectName(QStringLiteral("mainStatus"));
        mainStatus->setEnabled(false);
        mainStatus->setGeometry(QRect(460, 20, 110, 20));
        mainBalance = new QLineEdit(MainBox);
        mainBalance->setObjectName(QStringLiteral("mainBalance"));
        mainBalance->setEnabled(false);
        mainBalance->setGeometry(QRect(70, 50, 110, 20));
        mainPositionProfit = new QLineEdit(MainBox);
        mainPositionProfit->setObjectName(QStringLiteral("mainPositionProfit"));
        mainPositionProfit->setEnabled(false);
        mainPositionProfit->setGeometry(QRect(265, 50, 110, 20));
        mainCloseProfit = new QLineEdit(MainBox);
        mainCloseProfit->setObjectName(QStringLiteral("mainCloseProfit"));
        mainCloseProfit->setEnabled(false);
        mainCloseProfit->setGeometry(QRect(460, 50, 110, 20));
        beginFollowBtn = new QPushButton(MainBox);
        beginFollowBtn->setObjectName(QStringLiteral("beginFollowBtn"));
        beginFollowBtn->setGeometry(QRect(600, 20, 70, 50));
        stopFollowBtn = new QPushButton(MainBox);
        stopFollowBtn->setObjectName(QStringLiteral("stopFollowBtn"));
        stopFollowBtn->setEnabled(false);
        stopFollowBtn->setGeometry(QRect(690, 20, 70, 50));
        label = new QLabel(MainBox);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(25, 20, 40, 20));
        mainUsername = new QLineEdit(MainBox);
        mainUsername->setObjectName(QStringLiteral("mainUsername"));
        mainUsername->setEnabled(false);
        mainUsername->setGeometry(QRect(70, 20, 110, 20));
        label_3 = new QLabel(MainBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 20, 50, 20));
        mainBrokerName = new QLineEdit(MainBox);
        mainBrokerName->setObjectName(QStringLiteral("mainBrokerName"));
        mainBrokerName->setEnabled(false);
        mainBrokerName->setGeometry(QRect(265, 20, 110, 20));
        FollowBox = new QGroupBox(centralWidget);
        FollowBox->setObjectName(QStringLiteral("FollowBox"));
        FollowBox->setGeometry(QRect(10, 100, 780, 220));
        followView = new QTableWidget(FollowBox);
        if (followView->columnCount() < 9)
            followView->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        followView->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        followView->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        followView->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        followView->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        followView->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        followView->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        followView->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        followView->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        followView->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        followView->setObjectName(QStringLiteral("followView"));
        followView->setGeometry(QRect(10, 20, 760, 190));
        followView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        followView->setSelectionBehavior(QAbstractItemView::SelectRows);
        followView->horizontalHeader()->setHighlightSections(false);
        followView->verticalHeader()->setVisible(false);
        followView->verticalHeader()->setDefaultSectionSize(21);
        ReportBox = new QGroupBox(centralWidget);
        ReportBox->setObjectName(QStringLiteral("ReportBox"));
        ReportBox->setGeometry(QRect(10, 330, 780, 240));
        eventTable = new QTableView(ReportBox);
        eventTable->setObjectName(QStringLiteral("eventTable"));
        eventTable->setGeometry(QRect(10, 20, 760, 210));
        eventTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        eventTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        eventTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        eventTable->setSortingEnabled(true);
        eventTable->horizontalHeader()->setHighlightSections(false);
        eventTable->verticalHeader()->setVisible(false);
        eventTable->verticalHeader()->setDefaultSectionSize(21);
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindowClass->setMenuBar(menuBar);
#ifndef QT_NO_SHORTCUT
        label_5->setBuddy(mainStatus);
        label_6->setBuddy(mainBalance);
        label_8->setBuddy(mainPositionProfit);
        label_10->setBuddy(mainCloseProfit);
        label->setBuddy(mainUsername);
        label_3->setBuddy(mainBrokerName);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(mainSetting);
        menu->addAction(followSetting);
        menu_2->addAction(strategySetting);
        menu_3->addAction(brokerManage);

        retranslateUi(MainWindowClass);
        QObject::connect(beginFollowBtn, SIGNAL(clicked()), MainWindowClass, SLOT(beginFollowBtnClicked()));
        QObject::connect(stopFollowBtn, SIGNAL(clicked()), MainWindowClass, SLOT(stopFollowBtnClicked()));

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "\346\234\237\350\264\247\350\267\237\345\215\225\350\275\257\344\273\266", 0));
        mainSetting->setText(QApplication::translate("MainWindowClass", "\344\270\273\345\270\220\345\217\267\350\256\276\347\275\256", 0));
        followSetting->setText(QApplication::translate("MainWindowClass", "\346\240\267\346\234\254\350\264\246\345\217\267\350\256\276\347\275\256", 0));
        strategySetting->setText(QApplication::translate("MainWindowClass", "\350\267\237\345\215\225\347\255\226\347\225\245\350\256\276\347\275\256", 0));
        brokerManage->setText(QApplication::translate("MainWindowClass", "\346\234\215\345\212\241\345\231\250\347\256\241\347\220\206", 0));
        MainBox->setTitle(QApplication::translate("MainWindowClass", "\344\270\273\350\264\246\345\217\267", 0));
        label_5->setText(QApplication::translate("MainWindowClass", "\350\264\246\345\217\267\347\212\266\346\200\201", 0));
        label_6->setText(QApplication::translate("MainWindowClass", "\345\212\250\346\200\201\346\235\203\347\233\212", 0));
        label_8->setText(QApplication::translate("MainWindowClass", "\346\214\201\344\273\223\347\233\210\344\272\217", 0));
        label_10->setText(QApplication::translate("MainWindowClass", "\345\271\263\344\273\223\347\233\210\344\272\217", 0));
        mainStatus->setText(QApplication::translate("MainWindowClass", "\346\234\252\347\231\273\345\275\225", 0));
        mainBalance->setText(QApplication::translate("MainWindowClass", "0.00", 0));
        mainPositionProfit->setText(QApplication::translate("MainWindowClass", "0.00", 0));
        mainCloseProfit->setText(QApplication::translate("MainWindowClass", "0.00", 0));
        beginFollowBtn->setText(QApplication::translate("MainWindowClass", "\345\274\200\345\247\213\350\267\237\345\215\225", 0));
        stopFollowBtn->setText(QApplication::translate("MainWindowClass", "\345\201\234\346\255\242\350\267\237\345\215\225", 0));
        label->setText(QApplication::translate("MainWindowClass", "\344\270\273\350\264\246\345\217\267", 0));
        label_3->setText(QApplication::translate("MainWindowClass", "\346\234\237\350\264\247\345\205\254\345\217\270", 0));
        FollowBox->setTitle(QApplication::translate("MainWindowClass", "\346\240\267\346\234\254\350\264\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem = followView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindowClass", "\345\272\217\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = followView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindowClass", "\350\264\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = followView->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindowClass", "\346\234\237\350\264\247\345\205\254\345\217\270", 0));
        QTableWidgetItem *___qtablewidgetitem3 = followView->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindowClass", "\350\267\237\345\215\225\346\226\271\345\220\221", 0));
        QTableWidgetItem *___qtablewidgetitem4 = followView->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindowClass", "\350\267\237\345\215\225\346\257\224\344\276\213", 0));
        QTableWidgetItem *___qtablewidgetitem5 = followView->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindowClass", "\350\264\246\345\217\267\347\212\266\346\200\201", 0));
        QTableWidgetItem *___qtablewidgetitem6 = followView->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindowClass", "\345\212\250\346\200\201\346\235\203\347\233\212", 0));
        QTableWidgetItem *___qtablewidgetitem7 = followView->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindowClass", "\346\214\201\344\273\223\347\233\210\344\272\217", 0));
        QTableWidgetItem *___qtablewidgetitem8 = followView->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindowClass", "\345\271\263\344\273\223\347\233\210\344\272\217", 0));
        ReportBox->setTitle(QApplication::translate("MainWindowClass", "\350\277\220\350\241\214\346\227\245\345\277\227", 0));
        menu->setTitle(QApplication::translate("MainWindowClass", "\350\264\246\345\217\267\350\256\276\347\275\256", 0));
        menu_2->setTitle(QApplication::translate("MainWindowClass", "\350\267\237\345\215\225\350\256\276\347\275\256", 0));
        menu_3->setTitle(QApplication::translate("MainWindowClass", "\346\234\237\350\264\247\345\205\254\345\217\270\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
