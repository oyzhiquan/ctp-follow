/********************************************************************************
** Form generated from reading UI file 'brokermanage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROKERMANAGE_H
#define UI_BROKERMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_BrokerManageClass
{
public:
    QTableWidget *BrokerTable;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *insertButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QLineEdit *brokerName;
    QLineEdit *brokerID;
    QLineEdit *frontAddr;
    QPushButton *pushButton;

    void setupUi(QDialog *BrokerManageClass)
    {
        if (BrokerManageClass->objectName().isEmpty())
            BrokerManageClass->setObjectName(QStringLiteral("BrokerManageClass"));
        BrokerManageClass->resize(480, 333);
        BrokerManageClass->setModal(true);
        BrokerTable = new QTableWidget(BrokerManageClass);
        if (BrokerTable->columnCount() < 3)
            BrokerTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        BrokerTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        BrokerTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        BrokerTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        BrokerTable->setObjectName(QStringLiteral("BrokerTable"));
        BrokerTable->setGeometry(QRect(10, 10, 460, 220));
        BrokerTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        BrokerTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        BrokerTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        BrokerTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        BrokerTable->horizontalHeader()->setHighlightSections(false);
        BrokerTable->verticalHeader()->setVisible(false);
        BrokerTable->verticalHeader()->setDefaultSectionSize(21);
        label = new QLabel(BrokerManageClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 240, 90, 20));
        label_2 = new QLabel(BrokerManageClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(285, 240, 60, 20));
        label_3 = new QLabel(BrokerManageClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 270, 90, 20));
        insertButton = new QPushButton(BrokerManageClass);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setGeometry(QRect(20, 300, 75, 23));
        deleteButton = new QPushButton(BrokerManageClass);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(140, 300, 75, 23));
        updateButton = new QPushButton(BrokerManageClass);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(260, 300, 75, 23));
        brokerName = new QLineEdit(BrokerManageClass);
        brokerName->setObjectName(QStringLiteral("brokerName"));
        brokerName->setGeometry(QRect(110, 240, 141, 20));
        brokerID = new QLineEdit(BrokerManageClass);
        brokerID->setObjectName(QStringLiteral("brokerID"));
        brokerID->setGeometry(QRect(349, 240, 101, 20));
        frontAddr = new QLineEdit(BrokerManageClass);
        frontAddr->setObjectName(QStringLiteral("frontAddr"));
        frontAddr->setGeometry(QRect(110, 270, 340, 20));
        pushButton = new QPushButton(BrokerManageClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 300, 75, 23));

        retranslateUi(BrokerManageClass);
        QObject::connect(insertButton, SIGNAL(clicked()), BrokerManageClass, SLOT(insertBtnClicked()));
        QObject::connect(deleteButton, SIGNAL(clicked()), BrokerManageClass, SLOT(deleteBtnClicked()));
        QObject::connect(updateButton, SIGNAL(clicked()), BrokerManageClass, SLOT(updateBtnClicked()));
        QObject::connect(BrokerTable, SIGNAL(cellClicked(int,int)), BrokerManageClass, SLOT(CellClicked(int,int)));
        QObject::connect(pushButton, SIGNAL(clicked()), BrokerManageClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(BrokerManageClass);
    } // setupUi

    void retranslateUi(QDialog *BrokerManageClass)
    {
        BrokerManageClass->setWindowTitle(QApplication::translate("BrokerManageClass", "\346\234\237\350\264\247\345\205\254\345\217\270\347\256\241\347\220\206", 0));
        QTableWidgetItem *___qtablewidgetitem = BrokerTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BrokerManageClass", "\347\273\217\347\272\252\346\234\215\345\212\241\345\231\250\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = BrokerTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BrokerManageClass", "\347\273\217\347\272\252\345\225\206\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = BrokerTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BrokerManageClass", "\344\272\244\346\230\223\346\234\215\345\212\241\346\234\237\345\234\260\345\235\200", 0));
        label->setText(QApplication::translate("BrokerManageClass", "\347\273\217\347\272\252\346\234\215\345\212\241\345\231\250\345\220\215\347\247\260", 0));
        label_2->setText(QApplication::translate("BrokerManageClass", "\347\273\217\347\272\252\345\225\206\347\274\226\345\217\267", 0));
        label_3->setText(QApplication::translate("BrokerManageClass", "\344\272\244\346\230\223\346\234\215\345\212\241\346\234\237\345\234\260\345\235\200", 0));
        insertButton->setText(QApplication::translate("BrokerManageClass", "\345\242\236\345\212\240", 0));
        deleteButton->setText(QApplication::translate("BrokerManageClass", "\345\210\240\351\231\244", 0));
        updateButton->setText(QApplication::translate("BrokerManageClass", "\346\233\264\346\226\260", 0));
        pushButton->setText(QApplication::translate("BrokerManageClass", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class BrokerManageClass: public Ui_BrokerManageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROKERMANAGE_H
