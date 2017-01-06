/********************************************************************************
** Form generated from reading UI file 'TradeForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRADEFORM_H
#define UI_TRADEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TradeForm
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tradeTableWidget;

    void setupUi(QWidget *TradeForm)
    {
        if (TradeForm->objectName().isEmpty())
            TradeForm->setObjectName(QStringLiteral("TradeForm"));
        TradeForm->resize(400, 300);
        gridLayout = new QGridLayout(TradeForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tradeTableWidget = new QTableWidget(TradeForm);
        tradeTableWidget->setObjectName(QStringLiteral("tradeTableWidget"));

        gridLayout->addWidget(tradeTableWidget, 0, 0, 1, 1);


        retranslateUi(TradeForm);

        QMetaObject::connectSlotsByName(TradeForm);
    } // setupUi

    void retranslateUi(QWidget *TradeForm)
    {
        TradeForm->setWindowTitle(QApplication::translate("TradeForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TradeForm: public Ui_TradeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRADEFORM_H
