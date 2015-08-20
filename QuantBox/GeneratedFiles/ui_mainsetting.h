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
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *MainSettingClass)
    {
        if (MainSettingClass->objectName().isEmpty())
            MainSettingClass->setObjectName(QStringLiteral("MainSettingClass"));
        MainSettingClass->resize(395, 220);
        label = new QLabel(MainSettingClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 30, 20));
        lineEdit = new QLineEdit(MainSettingClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 20, 113, 20));
        label_2 = new QLabel(MainSettingClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 20, 30, 20));
        lineEdit_2 = new QLineEdit(MainSettingClass);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(260, 20, 113, 20));
        label_3 = new QLabel(MainSettingClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 60, 60, 20));
        label_4 = new QLabel(MainSettingClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 72, 20));
        label_5 = new QLabel(MainSettingClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 140, 91, 20));
        comboBox = new QComboBox(MainSettingClass);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 60, 151, 22));
        comboBox->setEditable(true);
        comboBox_2 = new QComboBox(MainSettingClass);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(110, 100, 151, 22));
        comboBox_2->setEditable(true);
        comboBox_3 = new QComboBox(MainSettingClass);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(110, 140, 261, 22));
        comboBox_3->setEditable(true);
        okButton = new QPushButton(MainSettingClass);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(180, 180, 81, 23));
        cancelButton = new QPushButton(MainSettingClass);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(290, 180, 81, 23));

        retranslateUi(MainSettingClass);
        QObject::connect(okButton, SIGNAL(clicked()), MainSettingClass, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), MainSettingClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(MainSettingClass);
    } // setupUi

    void retranslateUi(QDialog *MainSettingClass)
    {
        MainSettingClass->setWindowTitle(QApplication::translate("MainSettingClass", "\344\270\273\350\264\246\345\217\267\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("MainSettingClass", "\350\264\246 \345\217\267", 0));
        label_2->setText(QApplication::translate("MainSettingClass", "\345\257\206 \347\240\201", 0));
        label_3->setText(QApplication::translate("MainSettingClass", "\346\234\237\350\264\247\345\205\254\345\217\270ID", 0));
        label_4->setText(QApplication::translate("MainSettingClass", "\346\234\237\350\264\247\345\205\254\345\217\270\345\220\215\347\247\260", 0));
        label_5->setText(QApplication::translate("MainSettingClass", "\344\272\244\346\230\223\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        okButton->setText(QApplication::translate("MainSettingClass", "\344\277\235  \345\255\230", 0));
        cancelButton->setText(QApplication::translate("MainSettingClass", "\345\217\226  \346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class MainSettingClass: public Ui_MainSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSETTING_H
