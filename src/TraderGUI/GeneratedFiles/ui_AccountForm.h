/********************************************************************************
** Form generated from reading UI file 'AccountForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTFORM_H
#define UI_ACCOUNTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountForm
{
public:
    QGridLayout *gridLayout;
    QTableWidget *accountTableWidget;

    void setupUi(QWidget *AccountForm)
    {
        if (AccountForm->objectName().isEmpty())
            AccountForm->setObjectName(QStringLiteral("AccountForm"));
        AccountForm->resize(400, 300);
        gridLayout = new QGridLayout(AccountForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        accountTableWidget = new QTableWidget(AccountForm);
        accountTableWidget->setObjectName(QStringLiteral("accountTableWidget"));

        gridLayout->addWidget(accountTableWidget, 0, 0, 1, 1);


        retranslateUi(AccountForm);

        QMetaObject::connectSlotsByName(AccountForm);
    } // setupUi

    void retranslateUi(QWidget *AccountForm)
    {
        AccountForm->setWindowTitle(QApplication::translate("AccountForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AccountForm: public Ui_AccountForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTFORM_H
