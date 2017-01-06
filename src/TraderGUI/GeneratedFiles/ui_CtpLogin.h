/********************************************************************************
** Form generated from reading UI file 'CtpLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTPLOGIN_H
#define UI_CTPLOGIN_H

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

class Ui_CtpLogin
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *userNameLineEdit;
    QLabel *label_2;
    QLineEdit *passwordLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CtpLogin)
    {
        if (CtpLogin->objectName().isEmpty())
            CtpLogin->setObjectName(QStringLiteral("CtpLogin"));
        CtpLogin->resize(256, 93);
        gridLayout = new QGridLayout(CtpLogin);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(CtpLogin);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        userNameLineEdit = new QLineEdit(CtpLogin);
        userNameLineEdit->setObjectName(QStringLiteral("userNameLineEdit"));

        gridLayout->addWidget(userNameLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(CtpLogin);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        passwordLineEdit = new QLineEdit(CtpLogin);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(CtpLogin);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);


        retranslateUi(CtpLogin);

        QMetaObject::connectSlotsByName(CtpLogin);
    } // setupUi

    void retranslateUi(QDialog *CtpLogin)
    {
        CtpLogin->setWindowTitle(QApplication::translate("CtpLogin", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CtpLogin", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("CtpLogin", "\345\257\206  \347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CtpLogin: public Ui_CtpLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTPLOGIN_H
