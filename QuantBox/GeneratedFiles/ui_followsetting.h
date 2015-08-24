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
    QPushButton *insertButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QLineEdit *followBrokerID;
    QLineEdit *followTdFrontAddr;

    void setupUi(QDialog *FollowSettingClass)
    {
        if (FollowSettingClass->objectName().isEmpty())
            FollowSettingClass->setObjectName(QStringLiteral("FollowSettingClass"));
        FollowSettingClass->resize(500, 370);
        FollowSettingClass->setModal(true);
        closeButton = new QPushButton(FollowSettingClass);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(400, 328, 80, 24));
        followView = new QTableWidget(FollowSettingClass);
        if (followView->columnCount() < 5)
            followView->setColumnCount(5);
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
        followView->setObjectName(QStringLiteral("followView"));
        followView->setGeometry(QRect(10, 10, 480, 180));
        followView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        followView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        followView->setSelectionBehavior(QAbstractItemView::SelectRows);
        followView->horizontalHeader()->setHighlightSections(false);
        followView->verticalHeader()->setVisible(false);
        followView->verticalHeader()->setDefaultSectionSize(21);
        label = new QLabel(FollowSettingClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 210, 30, 20));
        label_2 = new QLabel(FollowSettingClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(245, 210, 30, 20));
        label_3 = new QLabel(FollowSettingClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 290, 61, 20));
        label_4 = new QLabel(FollowSettingClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 290, 61, 20));
        label_5 = new QLabel(FollowSettingClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 330, 60, 20));
        label_6 = new QLabel(FollowSettingClass);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 250, 50, 20));
        label_7 = new QLabel(FollowSettingClass);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(230, 250, 50, 20));
        followInverstID = new QLineEdit(FollowSettingClass);
        followInverstID->setObjectName(QStringLiteral("followInverstID"));
        followInverstID->setGeometry(QRect(75, 210, 130, 20));
        followPassword = new QLineEdit(FollowSettingClass);
        followPassword->setObjectName(QStringLiteral("followPassword"));
        followPassword->setGeometry(QRect(280, 210, 100, 20));
        followPassword->setEchoMode(QLineEdit::Password);
        followDirect = new QComboBox(FollowSettingClass);
        followDirect->setObjectName(QStringLiteral("followDirect"));
        followDirect->setGeometry(QRect(75, 250, 130, 20));
        followRatio = new QLineEdit(FollowSettingClass);
        followRatio->setObjectName(QStringLiteral("followRatio"));
        followRatio->setGeometry(QRect(280, 250, 100, 20));
        followBrokerName = new QComboBox(FollowSettingClass);
        followBrokerName->setObjectName(QStringLiteral("followBrokerName"));
        followBrokerName->setGeometry(QRect(75, 290, 130, 20));
        insertButton = new QPushButton(FollowSettingClass);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(400, 208, 80, 24));
        deleteButton = new QPushButton(FollowSettingClass);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(400, 248, 80, 24));
        updateButton = new QPushButton(FollowSettingClass);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(400, 288, 80, 24));
        followBrokerID = new QLineEdit(FollowSettingClass);
        followBrokerID->setObjectName(QStringLiteral("followBrokerID"));
        followBrokerID->setEnabled(false);
        followBrokerID->setGeometry(QRect(280, 290, 100, 20));
        followTdFrontAddr = new QLineEdit(FollowSettingClass);
        followTdFrontAddr->setObjectName(QStringLiteral("followTdFrontAddr"));
        followTdFrontAddr->setEnabled(false);
        followTdFrontAddr->setGeometry(QRect(75, 330, 305, 20));
        QWidget::setTabOrder(followInverstID, followPassword);
        QWidget::setTabOrder(followPassword, followDirect);
        QWidget::setTabOrder(followDirect, followRatio);
        QWidget::setTabOrder(followRatio, followBrokerName);
        QWidget::setTabOrder(followBrokerName, insertButton);
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
        QObject::connect(followBrokerName, SIGNAL(currentTextChanged(QString)), FollowSettingClass, SLOT(BrokerNameselected(QString)));

        QMetaObject::connectSlotsByName(FollowSettingClass);
    } // setupUi

    void retranslateUi(QDialog *FollowSettingClass)
    {
        FollowSettingClass->setWindowTitle(QApplication::translate("FollowSettingClass", "\350\267\237\350\270\252\350\264\246\345\217\267\350\256\276\347\275\256", 0));
        closeButton->setText(QApplication::translate("FollowSettingClass", "\345\205\263\351\227\255", 0));
        QTableWidgetItem *___qtablewidgetitem = followView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FollowSettingClass", "\350\264\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = followView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FollowSettingClass", "\346\234\237\350\264\247\345\205\254\345\217\270", 0));
        QTableWidgetItem *___qtablewidgetitem2 = followView->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FollowSettingClass", "\350\267\237\345\215\225\346\226\271\345\220\221", 0));
        QTableWidgetItem *___qtablewidgetitem3 = followView->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FollowSettingClass", "\350\267\237\345\215\225\346\257\224\344\276\213", 0));
        QTableWidgetItem *___qtablewidgetitem4 = followView->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("FollowSettingClass", "\345\257\206\347\240\201", 0));
        label->setText(QApplication::translate("FollowSettingClass", "\350\264\246 \345\217\267", 0));
        label_2->setText(QApplication::translate("FollowSettingClass", "\345\257\206 \347\240\201", 0));
        label_3->setText(QApplication::translate("FollowSettingClass", "\346\234\215\345\212\241\346\234\237\345\220\215\347\247\260", 0));
        label_4->setText(QApplication::translate("FollowSettingClass", "\347\273\217\347\272\252\345\225\206\347\274\226\345\217\267", 0));
        label_5->setText(QApplication::translate("FollowSettingClass", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        label_6->setText(QApplication::translate("FollowSettingClass", "\350\267\237\345\215\225\346\226\271\345\220\221", 0));
        label_7->setText(QApplication::translate("FollowSettingClass", "\350\267\237\345\215\225\346\257\224\344\276\213", 0));
        followDirect->clear();
        followDirect->insertItems(0, QStringList()
         << QApplication::translate("FollowSettingClass", "\346\255\243\345\220\221\350\267\237\345\215\225", 0)
         << QApplication::translate("FollowSettingClass", "\345\217\215\345\220\221\350\267\237\345\215\225", 0)
        );
        insertButton->setText(QApplication::translate("FollowSettingClass", "\345\242\236\345\212\240", 0));
        deleteButton->setText(QApplication::translate("FollowSettingClass", "\345\210\240\351\231\244", 0));
        updateButton->setText(QApplication::translate("FollowSettingClass", "\346\233\264\346\226\260", 0));
    } // retranslateUi

};

namespace Ui {
    class FollowSettingClass: public Ui_FollowSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOLLOWSETTING_H
