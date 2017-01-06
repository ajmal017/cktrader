/********************************************************************************
** Form generated from reading UI file 'CtpConfig.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTPCONFIG_H
#define UI_CTPCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CtpConfig
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *brokerIDLineEdit;
    QLabel *label_2;
    QLineEdit *mdAddressLineEdit;
    QLabel *label_3;
    QLineEdit *tdAddressLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CtpConfig)
    {
        if (CtpConfig->objectName().isEmpty())
            CtpConfig->setObjectName(QStringLiteral("CtpConfig"));
        CtpConfig->resize(400, 130);
        gridLayout = new QGridLayout(CtpConfig);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(CtpConfig);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        brokerIDLineEdit = new QLineEdit(CtpConfig);
        brokerIDLineEdit->setObjectName(QStringLiteral("brokerIDLineEdit"));

        gridLayout->addWidget(brokerIDLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(CtpConfig);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        mdAddressLineEdit = new QLineEdit(CtpConfig);
        mdAddressLineEdit->setObjectName(QStringLiteral("mdAddressLineEdit"));

        gridLayout->addWidget(mdAddressLineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(CtpConfig);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        tdAddressLineEdit = new QLineEdit(CtpConfig);
        tdAddressLineEdit->setObjectName(QStringLiteral("tdAddressLineEdit"));

        gridLayout->addWidget(tdAddressLineEdit, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(CtpConfig);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);


        retranslateUi(CtpConfig);

        QMetaObject::connectSlotsByName(CtpConfig);
    } // setupUi

    void retranslateUi(QDialog *CtpConfig)
    {
        CtpConfig->setWindowTitle(QApplication::translate("CtpConfig", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CtpConfig", "brokerID", Q_NULLPTR));
        label_2->setText(QApplication::translate("CtpConfig", "mdAddress", Q_NULLPTR));
        label_3->setText(QApplication::translate("CtpConfig", "tdAddress", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CtpConfig: public Ui_CtpConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTPCONFIG_H
