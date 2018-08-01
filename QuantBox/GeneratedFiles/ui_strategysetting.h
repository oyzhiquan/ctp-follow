/********************************************************************************
** Form generated from reading UI file 'strategysetting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRATEGYSETTING_H
#define UI_STRATEGYSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_StrategySettingClass
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *openActionSec;
    QComboBox *openPriceType;
    QSpinBox *openJump;
    QSpinBox *openTimes;
    QComboBox *openFinal;
    QComboBox *followType;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *closeActionSec;
    QComboBox *closePriceType;
    QSpinBox *closeJump;
    QSpinBox *closeTimes;
    QComboBox *closeFinal;

    void setupUi(QDialog *StrategySettingClass)
    {
        if (StrategySettingClass->objectName().isEmpty())
            StrategySettingClass->setObjectName(QStringLiteral("StrategySettingClass"));
        StrategySettingClass->resize(314, 281);
        StrategySettingClass->setModal(true);
        label = new QLabel(StrategySettingClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 48, 20));
        groupBox = new QGroupBox(StrategySettingClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 291, 111));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 161, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 50, 271, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 80, 141, 22));
        openActionSec = new QSpinBox(groupBox);
        openActionSec->setObjectName(QStringLiteral("openActionSec"));
        openActionSec->setGeometry(QRect(46, 21, 43, 20));
        openPriceType = new QComboBox(groupBox);
        openPriceType->setObjectName(QStringLiteral("openPriceType"));
        openPriceType->setGeometry(QRect(70, 51, 72, 20));
        openJump = new QSpinBox(groupBox);
        openJump->setObjectName(QStringLiteral("openJump"));
        openJump->setGeometry(QRect(197, 51, 43, 20));
        openTimes = new QSpinBox(groupBox);
        openTimes->setObjectName(QStringLiteral("openTimes"));
        openTimes->setGeometry(QRect(46, 81, 43, 20));
        openFinal = new QComboBox(groupBox);
        openFinal->setObjectName(QStringLiteral("openFinal"));
        openFinal->setGeometry(QRect(155, 81, 60, 20));
        followType = new QComboBox(StrategySettingClass);
        followType->setObjectName(QStringLiteral("followType"));
        followType->setGeometry(QRect(70, 10, 110, 20));
        pushButton = new QPushButton(StrategySettingClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 10, 75, 23));
        groupBox_2 = new QGroupBox(StrategySettingClass);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 160, 291, 111));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 20, 161, 22));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 50, 271, 22));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 80, 141, 22));
        closeActionSec = new QSpinBox(groupBox_2);
        closeActionSec->setObjectName(QStringLiteral("closeActionSec"));
        closeActionSec->setGeometry(QRect(46, 21, 43, 20));
        closePriceType = new QComboBox(groupBox_2);
        closePriceType->setObjectName(QStringLiteral("closePriceType"));
        closePriceType->setGeometry(QRect(70, 51, 72, 20));
        closeJump = new QSpinBox(groupBox_2);
        closeJump->setObjectName(QStringLiteral("closeJump"));
        closeJump->setGeometry(QRect(197, 51, 43, 20));
        closeTimes = new QSpinBox(groupBox_2);
        closeTimes->setObjectName(QStringLiteral("closeTimes"));
        closeTimes->setGeometry(QRect(46, 81, 43, 20));
        closeFinal = new QComboBox(groupBox_2);
        closeFinal->setObjectName(QStringLiteral("closeFinal"));
        closeFinal->setGeometry(QRect(155, 81, 60, 20));
        QWidget::setTabOrder(followType, openActionSec);
        QWidget::setTabOrder(openActionSec, openPriceType);
        QWidget::setTabOrder(openPriceType, openJump);
        QWidget::setTabOrder(openJump, openTimes);
        QWidget::setTabOrder(openTimes, openFinal);
        QWidget::setTabOrder(openFinal, closeActionSec);
        QWidget::setTabOrder(closeActionSec, closePriceType);
        QWidget::setTabOrder(closePriceType, closeJump);
        QWidget::setTabOrder(closeJump, closeTimes);
        QWidget::setTabOrder(closeTimes, closeFinal);
        QWidget::setTabOrder(closeFinal, pushButton);

        retranslateUi(StrategySettingClass);
        QObject::connect(pushButton, SIGNAL(clicked()), StrategySettingClass, SLOT(saveBtnClicked()));

        QMetaObject::connectSlotsByName(StrategySettingClass);
    } // setupUi

    void retranslateUi(QDialog *StrategySettingClass)
    {
        StrategySettingClass->setWindowTitle(QApplication::translate("StrategySettingClass", "\350\267\237\345\215\225\347\255\226\347\225\245\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("StrategySettingClass", "\344\273\267\346\240\274\347\255\226\347\225\245", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("StrategySettingClass", "\345\274\200\344\273\223\345\215\225\347\255\226\347\225\245", Q_NULLPTR));
        label_2->setText(QApplication::translate("StrategySettingClass", "\345\247\224\346\211\230        \347\247\222\344\270\215\346\210\220\344\272\244\346\222\244\345\215\225", Q_NULLPTR));
        label_3->setText(QApplication::translate("StrategySettingClass", "\346\222\244\345\215\225\345\220\216\344\273\245             \344\273\267\346\240\274\345\201\217\347\246\273        \350\267\263\350\277\275\345\215\225", Q_NULLPTR));
        label_4->setText(QApplication::translate("StrategySettingClass", "\350\277\275\345\215\225        \346\254\241\345\220\216\344\270\215\346\210\220\344\272\244", Q_NULLPTR));
        openPriceType->clear();
        openPriceType->insertItems(0, QStringList()
         << QApplication::translate("StrategySettingClass", "\345\247\224\346\211\230\344\273\267\346\240\274", Q_NULLPTR)
         << QApplication::translate("StrategySettingClass", "\346\234\200\346\226\260\344\273\267\346\240\274", Q_NULLPTR)
        );
        openFinal->clear();
        openFinal->insertItems(0, QStringList()
         << QApplication::translate("StrategySettingClass", "\346\222\244\345\215\225", Q_NULLPTR)
         << QApplication::translate("StrategySettingClass", "\346\214\202\345\215\225", Q_NULLPTR)
        );
        followType->clear();
        followType->insertItems(0, QStringList()
         << QApplication::translate("StrategySettingClass", "\346\240\267\346\234\254\346\210\220\344\272\244\344\273\267\350\267\237\345\215\225", Q_NULLPTR)
         << QApplication::translate("StrategySettingClass", "\345\270\202\344\273\267\350\267\237\345\215\225", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("StrategySettingClass", "\344\277\235\345\255\230", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("StrategySettingClass", "\345\271\263\344\273\223\345\215\225\347\255\226\347\225\245", Q_NULLPTR));
        label_5->setText(QApplication::translate("StrategySettingClass", "\345\247\224\346\211\230        \347\247\222\344\270\215\346\210\220\344\272\244\346\222\244\345\215\225", Q_NULLPTR));
        label_6->setText(QApplication::translate("StrategySettingClass", "\346\222\244\345\215\225\345\220\216\344\273\245             \344\273\267\346\240\274\345\201\217\347\246\273        \350\267\263\350\277\275\345\215\225", Q_NULLPTR));
        label_7->setText(QApplication::translate("StrategySettingClass", "\350\277\275\345\215\225        \346\254\241\345\220\216\344\270\215\346\210\220\344\272\244", Q_NULLPTR));
        closePriceType->clear();
        closePriceType->insertItems(0, QStringList()
         << QApplication::translate("StrategySettingClass", "\345\247\224\346\211\230\344\273\267\346\240\274", Q_NULLPTR)
         << QApplication::translate("StrategySettingClass", "\346\234\200\346\226\260\344\273\267\346\240\274", Q_NULLPTR)
        );
        closeFinal->clear();
        closeFinal->insertItems(0, QStringList()
         << QApplication::translate("StrategySettingClass", "\346\222\244\345\215\225", Q_NULLPTR)
         << QApplication::translate("StrategySettingClass", "\346\214\202\345\215\225", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class StrategySettingClass: public Ui_StrategySettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRATEGYSETTING_H
