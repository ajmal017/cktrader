/********************************************************************************
** Form generated from reading UI file 'TickForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKFORM_H
#define UI_TICKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TickForm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableWidget *tickTable;
    QHBoxLayout *horizontalLayout;
    QLineEdit *contractLineEdit;
    QDoubleSpinBox *priceDoubleSpinBox;
    QDoubleSpinBox *volDoubleSpinBox;
    QComboBox *priceTypeComboBox;
    QComboBox *directionComboBox;
    QComboBox *offsetComboBox;
    QComboBox *currencyComboBox;
    QPushButton *orderPushButton;

    void setupUi(QWidget *TickForm)
    {
        if (TickForm->objectName().isEmpty())
            TickForm->setObjectName(QStringLiteral("TickForm"));
        TickForm->resize(593, 261);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TickForm->sizePolicy().hasHeightForWidth());
        TickForm->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(TickForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tickTable = new QTableWidget(TickForm);
        tickTable->setObjectName(QStringLiteral("tickTable"));
        tickTable->setRowCount(0);

        verticalLayout->addWidget(tickTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        contractLineEdit = new QLineEdit(TickForm);
        contractLineEdit->setObjectName(QStringLiteral("contractLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(contractLineEdit->sizePolicy().hasHeightForWidth());
        contractLineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(contractLineEdit);

        priceDoubleSpinBox = new QDoubleSpinBox(TickForm);
        priceDoubleSpinBox->setObjectName(QStringLiteral("priceDoubleSpinBox"));
        sizePolicy1.setHeightForWidth(priceDoubleSpinBox->sizePolicy().hasHeightForWidth());
        priceDoubleSpinBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(priceDoubleSpinBox);

        volDoubleSpinBox = new QDoubleSpinBox(TickForm);
        volDoubleSpinBox->setObjectName(QStringLiteral("volDoubleSpinBox"));
        sizePolicy1.setHeightForWidth(volDoubleSpinBox->sizePolicy().hasHeightForWidth());
        volDoubleSpinBox->setSizePolicy(sizePolicy1);
        volDoubleSpinBox->setValue(1);

        horizontalLayout->addWidget(volDoubleSpinBox);

        priceTypeComboBox = new QComboBox(TickForm);
        priceTypeComboBox->setObjectName(QStringLiteral("priceTypeComboBox"));

        horizontalLayout->addWidget(priceTypeComboBox);

        directionComboBox = new QComboBox(TickForm);
        directionComboBox->setObjectName(QStringLiteral("directionComboBox"));

        horizontalLayout->addWidget(directionComboBox);

        offsetComboBox = new QComboBox(TickForm);
        offsetComboBox->setObjectName(QStringLiteral("offsetComboBox"));

        horizontalLayout->addWidget(offsetComboBox);

        currencyComboBox = new QComboBox(TickForm);
        currencyComboBox->setObjectName(QStringLiteral("currencyComboBox"));

        horizontalLayout->addWidget(currencyComboBox);

        orderPushButton = new QPushButton(TickForm);
        orderPushButton->setObjectName(QStringLiteral("orderPushButton"));
        sizePolicy1.setHeightForWidth(orderPushButton->sizePolicy().hasHeightForWidth());
        orderPushButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(orderPushButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(TickForm);

        QMetaObject::connectSlotsByName(TickForm);
    } // setupUi

    void retranslateUi(QWidget *TickForm)
    {
        TickForm->setWindowTitle(QApplication::translate("TickForm", "Form", Q_NULLPTR));
        contractLineEdit->setPlaceholderText(QApplication::translate("TickForm", "\345\220\210\347\272\246\345\220\215\347\247\260", Q_NULLPTR));
        priceTypeComboBox->clear();
        priceTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("TickForm", "\345\270\202\344\273\267", Q_NULLPTR)
         << QApplication::translate("TickForm", "\351\231\220\344\273\267", Q_NULLPTR)
         << QApplication::translate("TickForm", "FAK", Q_NULLPTR)
         << QApplication::translate("TickForm", "FOK", Q_NULLPTR)
        );
        directionComboBox->clear();
        directionComboBox->insertItems(0, QStringList()
         << QApplication::translate("TickForm", "\345\244\232", Q_NULLPTR)
         << QApplication::translate("TickForm", "\347\251\272", Q_NULLPTR)
        );
        offsetComboBox->clear();
        offsetComboBox->insertItems(0, QStringList()
         << QApplication::translate("TickForm", "\345\274\200\344\273\223", Q_NULLPTR)
         << QApplication::translate("TickForm", "\345\271\263\344\273\223", Q_NULLPTR)
         << QApplication::translate("TickForm", "\345\271\263\344\273\212", Q_NULLPTR)
         << QApplication::translate("TickForm", "\345\271\263\346\230\250", Q_NULLPTR)
        );
        currencyComboBox->clear();
        currencyComboBox->insertItems(0, QStringList()
         << QApplication::translate("TickForm", "CNY", Q_NULLPTR)
         << QApplication::translate("TickForm", "USD", Q_NULLPTR)
        );
        orderPushButton->setText(QApplication::translate("TickForm", "\345\217\221\351\200\201\350\256\242\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TickForm: public Ui_TickForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKFORM_H
