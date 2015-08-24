/********************************************************************************
** Form generated from reading UI file 'mainsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSETTING_H
#define UI_MAINSETTING_H

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

QT_BEGIN_NAMESPACE

class Ui_MainSettingClass
{
public:
    QLabel *label;
    QLineEdit *inverstID;
    QLabel *label_2;
    QLineEdit *password;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *brokerName;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QLineEdit *brokerID;
    QLineEdit *frontAddr;

    void setupUi(QDialog *MainSettingClass)
    {
        if (MainSettingClass->objectName().isEmpty())
            MainSettingClass->setObjectName(QStringLiteral("MainSettingClass"));
        MainSettingClass->resize(370, 220);
        label = new QLabel(MainSettingClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 30, 20));
        inverstID = new QLineEdit(MainSettingClass);
        inverstID->setObjectName(QStringLiteral("inverstID"));
        inverstID->setGeometry(QRect(60, 20, 110, 20));
        label_2 = new QLabel(MainSettingClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 20, 30, 20));
        password = new QLineEdit(MainSettingClass);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(240, 20, 110, 20));
        password->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(MainSettingClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 100, 65, 20));
        label_4 = new QLabel(MainSettingClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 60, 65, 20));
        label_5 = new QLabel(MainSettingClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 140, 65, 20));
        brokerName = new QComboBox(MainSettingClass);
        brokerName->setObjectName(QStringLiteral("brokerName"));
        brokerName->setGeometry(QRect(85, 60, 180, 20));
        brokerName->setEditable(false);
        saveButton = new QPushButton(MainSettingClass);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(160, 180, 81, 23));
        cancelButton = new QPushButton(MainSettingClass);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(270, 180, 81, 23));
        brokerID = new QLineEdit(MainSettingClass);
        brokerID->setObjectName(QStringLiteral("brokerID"));
        brokerID->setEnabled(false);
        brokerID->setGeometry(QRect(85, 100, 180, 20));
        frontAddr = new QLineEdit(MainSettingClass);
        frontAddr->setObjectName(QStringLiteral("frontAddr"));
        frontAddr->setEnabled(false);
        frontAddr->setGeometry(QRect(85, 140, 265, 20));

        retranslateUi(MainSettingClass);
        QObject::connect(saveButton, SIGNAL(clicked()), MainSettingClass, SLOT(saveBtnClicked()));
        QObject::connect(cancelButton, SIGNAL(clicked()), MainSettingClass, SLOT(reject()));
        QObject::connect(brokerName, SIGNAL(currentTextChanged(QString)), MainSettingClass, SLOT(BrokerNameselected(QString)));

        QMetaObject::connectSlotsByName(MainSettingClass);
    } // setupUi

    void retranslateUi(QDialog *MainSettingClass)
    {
        MainSettingClass->setWindowTitle(QApplication::translate("MainSettingClass", "\344\270\273\350\264\246\345\217\267\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("MainSettingClass", "\350\264\246 \345\217\267", 0));
        label_2->setText(QApplication::translate("MainSettingClass", "\345\257\206 \347\240\201", 0));
        label_3->setText(QApplication::translate("MainSettingClass", "\347\273\217\347\272\252\345\225\206\347\274\226\345\217\267", 0));
        label_4->setText(QApplication::translate("MainSettingClass", "\346\234\215\345\212\241\345\231\250\345\220\215\347\247\260", 0));
        label_5->setText(QApplication::translate("MainSettingClass", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        saveButton->setText(QApplication::translate("MainSettingClass", "\344\277\235  \345\255\230", 0));
        cancelButton->setText(QApplication::translate("MainSettingClass", "\345\217\226  \346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class MainSettingClass: public Ui_MainSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSETTING_H
