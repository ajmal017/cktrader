/********************************************************************************
** Form generated from reading UI file 'ContractForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRACTFORM_H
#define UI_CONTRACTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContractForm
{
public:
    QGridLayout *gridLayout;
    QTableWidget *ContractTableWidget;

    void setupUi(QWidget *ContractForm)
    {
        if (ContractForm->objectName().isEmpty())
            ContractForm->setObjectName(QStringLiteral("ContractForm"));
        ContractForm->resize(400, 300);
        gridLayout = new QGridLayout(ContractForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ContractTableWidget = new QTableWidget(ContractForm);
        ContractTableWidget->setObjectName(QStringLiteral("ContractTableWidget"));

        gridLayout->addWidget(ContractTableWidget, 0, 0, 1, 1);


        retranslateUi(ContractForm);

        QMetaObject::connectSlotsByName(ContractForm);
    } // setupUi

    void retranslateUi(QWidget *ContractForm)
    {
        ContractForm->setWindowTitle(QApplication::translate("ContractForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ContractForm: public Ui_ContractForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRACTFORM_H
