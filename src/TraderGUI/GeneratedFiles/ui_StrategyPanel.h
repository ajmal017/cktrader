/********************************************************************************
** Form generated from reading UI file 'StrategyPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRATEGYPANEL_H
#define UI_STRATEGYPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StrategyPanel
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *init_strategy_pushButton;
    QPushButton *begin_trade_pushButton;
    QPushButton *stop_trade_pushButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *paramter_set_pushButton;
    QPushButton *back_test_pushButton;
    QPushButton *risk_manage_pushButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *postionPushButton;
    QPushButton *tradePushButton;
    QPushButton *orderPushButton;

    void setupUi(QWidget *StrategyPanel)
    {
        if (StrategyPanel->objectName().isEmpty())
            StrategyPanel->setObjectName(QStringLiteral("StrategyPanel"));
        StrategyPanel->resize(271, 107);
        gridLayout = new QGridLayout(StrategyPanel);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        init_strategy_pushButton = new QPushButton(StrategyPanel);
        init_strategy_pushButton->setObjectName(QStringLiteral("init_strategy_pushButton"));

        horizontalLayout->addWidget(init_strategy_pushButton);

        begin_trade_pushButton = new QPushButton(StrategyPanel);
        begin_trade_pushButton->setObjectName(QStringLiteral("begin_trade_pushButton"));

        horizontalLayout->addWidget(begin_trade_pushButton);

        stop_trade_pushButton = new QPushButton(StrategyPanel);
        stop_trade_pushButton->setObjectName(QStringLiteral("stop_trade_pushButton"));

        horizontalLayout->addWidget(stop_trade_pushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        paramter_set_pushButton = new QPushButton(StrategyPanel);
        paramter_set_pushButton->setObjectName(QStringLiteral("paramter_set_pushButton"));

        horizontalLayout_2->addWidget(paramter_set_pushButton);

        back_test_pushButton = new QPushButton(StrategyPanel);
        back_test_pushButton->setObjectName(QStringLiteral("back_test_pushButton"));

        horizontalLayout_2->addWidget(back_test_pushButton);

        risk_manage_pushButton = new QPushButton(StrategyPanel);
        risk_manage_pushButton->setObjectName(QStringLiteral("risk_manage_pushButton"));

        horizontalLayout_2->addWidget(risk_manage_pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        postionPushButton = new QPushButton(StrategyPanel);
        postionPushButton->setObjectName(QStringLiteral("postionPushButton"));

        horizontalLayout_3->addWidget(postionPushButton);

        tradePushButton = new QPushButton(StrategyPanel);
        tradePushButton->setObjectName(QStringLiteral("tradePushButton"));

        horizontalLayout_3->addWidget(tradePushButton);

        orderPushButton = new QPushButton(StrategyPanel);
        orderPushButton->setObjectName(QStringLiteral("orderPushButton"));

        horizontalLayout_3->addWidget(orderPushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(StrategyPanel);

        QMetaObject::connectSlotsByName(StrategyPanel);
    } // setupUi

    void retranslateUi(QWidget *StrategyPanel)
    {
        StrategyPanel->setWindowTitle(QApplication::translate("StrategyPanel", "Form", Q_NULLPTR));
        init_strategy_pushButton->setText(QApplication::translate("StrategyPanel", "\345\210\235\345\247\213\345\214\226\347\255\226\347\225\245", Q_NULLPTR));
        begin_trade_pushButton->setText(QApplication::translate("StrategyPanel", "\345\274\200\345\247\213\344\272\244\346\230\223", Q_NULLPTR));
        stop_trade_pushButton->setText(QApplication::translate("StrategyPanel", "\345\201\234\346\255\242\344\272\244\346\230\223", Q_NULLPTR));
        paramter_set_pushButton->setText(QApplication::translate("StrategyPanel", "\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        back_test_pushButton->setText(QApplication::translate("StrategyPanel", "\345\233\236\346\265\213", Q_NULLPTR));
        risk_manage_pushButton->setText(QApplication::translate("StrategyPanel", "\351\243\216\351\231\251\347\256\241\347\220\206", Q_NULLPTR));
        postionPushButton->setText(QApplication::translate("StrategyPanel", "\347\255\226\347\225\245\346\214\201\344\273\223", Q_NULLPTR));
        tradePushButton->setText(QApplication::translate("StrategyPanel", "\347\255\226\347\225\245\345\247\224\346\211\230", Q_NULLPTR));
        orderPushButton->setText(QApplication::translate("StrategyPanel", "\347\255\226\347\225\245\346\210\220\344\272\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StrategyPanel: public Ui_StrategyPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRATEGYPANEL_H
