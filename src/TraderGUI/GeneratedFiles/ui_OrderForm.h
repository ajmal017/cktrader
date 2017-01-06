/********************************************************************************
** Form generated from reading UI file 'OrderForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERFORM_H
#define UI_ORDERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderForm
{
public:
    QGridLayout *gridLayout;
    QTableWidget *orderTableWidget;

    void setupUi(QWidget *OrderForm)
    {
        if (OrderForm->objectName().isEmpty())
            OrderForm->setObjectName(QStringLiteral("OrderForm"));
        OrderForm->resize(400, 300);
        gridLayout = new QGridLayout(OrderForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        orderTableWidget = new QTableWidget(OrderForm);
        orderTableWidget->setObjectName(QStringLiteral("orderTableWidget"));

        gridLayout->addWidget(orderTableWidget, 0, 0, 1, 1);


        retranslateUi(OrderForm);

        QMetaObject::connectSlotsByName(OrderForm);
    } // setupUi

    void retranslateUi(QWidget *OrderForm)
    {
        OrderForm->setWindowTitle(QApplication::translate("OrderForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OrderForm: public Ui_OrderForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERFORM_H
