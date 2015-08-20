/********************************************************************************
** Form generated from reading UI file 'followsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOLLOWSETTING_H
#define UI_FOLLOWSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_FollowSettingClass
{
public:
    QPushButton *closeButton;
    QTableWidget *followView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *followInverstID;
    QLineEdit *followPassword;
    QComboBox *followDirect;
    QLineEdit *followRatio;
    QComboBox *followBrokerName;
    QComboBox *followBrokerID;
    QComboBox *followTdFrontAddr;
    QPushButton *insertButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;

    void setupUi(QDialog *FollowSettingClass)
    {
        if (FollowSettingClass->objectName().isEmpty())
            FollowSettingClass->setObjectName(QStringLiteral("FollowSettingClass"));
        FollowSettingClass->resize(780, 340);
        FollowSettingClass->setModal(true);
        closeButton = new QPushButton(FollowSettingClass);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(610, 300, 100, 23));
        followView = new QTableWidget(FollowSettingClass);
        if (followView->columnCount() < 7)
            followView->setColumnCount(7);
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
        followView->setObjectName(QStringLiteral("followView"));
        followView->setGeometry(QRect(10, 10, 760, 190));
        followView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        followView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        followView->setSelectionBehavior(QAbstractItemView::SelectRows);
        followView->horizontalHeader()->setHighlightSections(false);
        followView->verticalHeader()->setVisible(false);
        followView->verticalHeader()->setDefaultSectionSize(21);
        label = new QLabel(FollowSettingClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 220, 30, 20));
        label_2 = new QLabel(FollowSettingClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 220, 30, 20));
        label_3 = new QLabel(FollowSettingClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 260, 50, 20));
        label_4 = new QLabel(FollowSettingClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 260, 50, 20));
        label_5 = new QLabel(FollowSettingClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(380, 260, 60, 20));
        label_6 = new QLabel(FollowSettingClass);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(390, 220, 50, 20));
        label_7 = new QLabel(FollowSettingClass);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(590, 220, 50, 20));
        followInverstID = new QLineEdit(FollowSettingClass);
        followInverstID->setObjectName(QStringLiteral("followInverstID"));
        followInverstID->setGeometry(QRect(70, 220, 110, 20));
        followPassword = new QLineEdit(FollowSettingClass);
        followPassword->setObjectName(QStringLiteral("followPassword"));
        followPassword->setGeometry(QRect(250, 220, 110, 20));
        followPassword->setEchoMode(QLineEdit::Password);
        followDirect = new QComboBox(FollowSettingClass);
        followDirect->setObjectName(QStringLiteral("followDirect"));
        followDirect->setGeometry(QRect(450, 220, 110, 20));
        followRatio = new QLineEdit(FollowSettingClass);
        followRatio->setObjectName(QStringLiteral("followRatio"));
        followRatio->setGeometry(QRect(650, 220, 110, 20));
        followBrokerName = new QComboBox(FollowSettingClass);
        followBrokerName->setObjectName(QStringLiteral("followBrokerName"));
        followBrokerName->setGeometry(QRect(70, 260, 110, 20));
        followBrokerName->setEditable(true);
        followBrokerID = new QComboBox(FollowSettingClass);
        followBrokerID->setObjectName(QStringLiteral("followBrokerID"));
        followBrokerID->setGeometry(QRect(250, 260, 110, 20));
        followBrokerID->setEditable(true);
        followTdFrontAddr = new QComboBox(FollowSettingClass);
        followTdFrontAddr->setObjectName(QStringLiteral("followTdFrontAddr"));
        followTdFrontAddr->setGeometry(QRect(450, 260, 310, 20));
        followTdFrontAddr->setEditable(true);
        insertButton = new QPushButton(FollowSettingClass);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(70, 300, 100, 23));
        deleteButton = new QPushButton(FollowSettingClass);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(250, 300, 100, 23));
        updateButton = new QPushButton(FollowSettingClass);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(430, 300, 100, 23));
        QWidget::setTabOrder(followInverstID, followPassword);
        QWidget::setTabOrder(followPassword, followDirect);
        QWidget::setTabOrder(followDirect, followRatio);
        QWidget::setTabOrder(followRatio, followBrokerName);
        QWidget::setTabOrder(followBrokerName, followBrokerID);
        QWidget::setTabOrder(followBrokerID, followTdFrontAddr);
        QWidget::setTabOrder(followTdFrontAddr, insertButton);
        QWidget::setTabOrder(insertButton, deleteButton);
        QWidget::setTabOrder(deleteButton, updateButton);
        QWidget::setTabOrder(updateButton, closeButton);
        QWidget::setTabOrder(closeButton, followView);

        retranslateUi(FollowSettingClass);
        QObject::connect(closeButton, SIGNAL(clicked()), FollowSettingClass, SLOT(reject()));
        QObject::connect(followView, SIGNAL(cellClicked(int,int)), FollowSettingClass, SLOT(followCellClicked(int,int)));
        QObject::connect(insertButton, SIGNAL(clicked()), FollowSettingClass, SLOT(insertBtnClicked()));
        QObject::connect(deleteButton, SIGNAL(clicked()), FollowSettingClass, SLOT(deleteBtnClicked()));
        QObject::connect(updateButton, SIGNAL(clicked()), FollowSettingClass, SLOT(updateBtnClicked()));

        QMetaObject::connectSlotsByName(FollowSettingClass);
    } // setupUi

    void retranslateUi(QDialog *FollowSettingClass)
    {
        FollowSettingClass->setWindowTitle(QApplication::translate("FollowSettingClass", "\350\267\237\350\270\252\350\264\246\345\217\267\350\256\276\347\275\256", 0));
        closeButton->setText(QApplication::translate("FollowSettingClass", "\345\205\263\351\227\255\347\252\227\345\217\243", 0));
        QTableWidgetItem *___qtablewidgetitem = followView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FollowSettingClass", "\350\264\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = followView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FollowSettingClass", "\346\234\237\350\264\247\345\205\254\345\217\270", 0));
        QTableWidgetItem *___qtablewidgetitem2 = followView->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FollowSettingClass", "\346\234\237\350\264\247\345\270\255\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem3 = followView->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FollowSettingClass", "\344\272\244\346\230\223\346\234\215\345\212\241\345\231\250", 0));
        QTableWidgetItem *___qtablewidgetitem4 = followView->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("FollowSettingClass", "\350\267\237\345\215\225\346\226\271\345\220\221", 0));
        QTableWidgetItem *___qtablewidgetitem5 = followView->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("FollowSettingClass", "\350\267\237\345\215\225\346\257\224\344\276\213", 0));
        QTableWidgetItem *___qtablewidgetitem6 = followView->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("FollowSettingClass", "\345\257\206\347\240\201", 0));
        label->setText(QApplication::translate("FollowSettingClass", "\350\264\246 \345\217\267", 0));
        label_2->setText(QApplication::translate("FollowSettingClass", "\345\257\206 \347\240\201", 0));
        label_3->setText(QApplication::translate("FollowSettingClass", "\346\234\237\350\264\247\345\205\254\345\217\270", 0));
        label_4->setText(QApplication::translate("FollowSettingClass", "\346\234\237\350\264\247\345\270\255\344\275\215", 0));
        label_5->setText(QApplication::translate("FollowSettingClass", "\344\272\244\346\230\223\346\234\215\345\212\241\345\231\250", 0));
        label_6->setText(QApplication::translate("FollowSettingClass", "\350\267\237\345\215\225\346\226\271\345\220\221", 0));
        label_7->setText(QApplication::translate("FollowSettingClass", "\350\267\237\345\215\225\346\257\224\344\276\213", 0));
        followDirect->clear();
        followDirect->insertItems(0, QStringList()
         << QApplication::translate("FollowSettingClass", "\346\255\243\345\220\221\350\267\237\345\215\225", 0)
         << QApplication::translate("FollowSettingClass", "\345\217\215\345\220\221\350\267\237\345\215\225", 0)
        );
        insertButton->setText(QApplication::translate("FollowSettingClass", "\345\242\236\345\212\240\350\264\246\345\217\267", 0));
        deleteButton->setText(QApplication::translate("FollowSettingClass", "\345\210\240\351\231\244\350\264\246\345\217\267", 0));
        updateButton->setText(QApplication::translate("FollowSettingClass", "\346\233\264\346\226\260\350\264\246\345\217\267", 0));
    } // retranslateUi

};

namespace Ui {
    class FollowSettingClass: public Ui_FollowSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOLLOWSETTING_H
