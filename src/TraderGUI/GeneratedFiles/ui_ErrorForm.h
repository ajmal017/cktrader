/********************************************************************************
** Form generated from reading UI file 'ErrorForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORFORM_H
#define UI_ERRORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorForm
{
public:
    QGridLayout *gridLayout;
    QTableWidget *errorTableWidget;

    void setupUi(QWidget *ErrorForm)
    {
        if (ErrorForm->objectName().isEmpty())
            ErrorForm->setObjectName(QStringLiteral("ErrorForm"));
        ErrorForm->resize(400, 300);
        gridLayout = new QGridLayout(ErrorForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        errorTableWidget = new QTableWidget(ErrorForm);
        errorTableWidget->setObjectName(QStringLiteral("errorTableWidget"));

        gridLayout->addWidget(errorTableWidget, 0, 0, 1, 1);


        retranslateUi(ErrorForm);

        QMetaObject::connectSlotsByName(ErrorForm);
    } // setupUi

    void retranslateUi(QWidget *ErrorForm)
    {
        ErrorForm->setWindowTitle(QApplication::translate("ErrorForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ErrorForm: public Ui_ErrorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORFORM_H
