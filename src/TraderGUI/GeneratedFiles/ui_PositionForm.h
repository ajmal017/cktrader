/********************************************************************************
** Form generated from reading UI file 'PositionForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONFORM_H
#define UI_POSITIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PositionForm
{
public:
    QGridLayout *gridLayout;
    QTableWidget *positionTableWidget;

    void setupUi(QWidget *PositionForm)
    {
        if (PositionForm->objectName().isEmpty())
            PositionForm->setObjectName(QStringLiteral("PositionForm"));
        PositionForm->resize(400, 300);
        gridLayout = new QGridLayout(PositionForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        positionTableWidget = new QTableWidget(PositionForm);
        positionTableWidget->setObjectName(QStringLiteral("positionTableWidget"));

        gridLayout->addWidget(positionTableWidget, 0, 0, 1, 1);


        retranslateUi(PositionForm);

        QMetaObject::connectSlotsByName(PositionForm);
    } // setupUi

    void retranslateUi(QWidget *PositionForm)
    {
        PositionForm->setWindowTitle(QApplication::translate("PositionForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PositionForm: public Ui_PositionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONFORM_H
