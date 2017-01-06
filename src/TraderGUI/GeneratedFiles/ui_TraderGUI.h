/********************************************************************************
** Form generated from reading UI file 'TraderGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRADERGUI_H
#define UI_TRADERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TraderGUIClass
{
public:
    QAction *ctpActionLogin;
    QAction *ctpActionLogout;
    QAction *ltsActionLogin;
    QAction *ltsActionLogout;
    QAction *ibActionLogin;
    QAction *ibActionLogout;
    QAction *actionQuit;
    QAction *ctpActionConfig;
    QAction *ltsActionConfig;
    QAction *ibActionConfig;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *horizontal_splitter;
    QWidget *strategy_widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabMarket;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabLeft;
    QTabWidget *tabRight;
    QMenuBar *menuBar;
    QMenu *menuGateway;
    QMenu *menuCTP;
    QMenu *menuLST;
    QMenu *menuIB;
    QMenu *menuStrategy;
    QMenu *menuRisk;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TraderGUIClass)
    {
        if (TraderGUIClass->objectName().isEmpty())
            TraderGUIClass->setObjectName(QStringLiteral("TraderGUIClass"));
        TraderGUIClass->resize(801, 614);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TraderGUIClass->sizePolicy().hasHeightForWidth());
        TraderGUIClass->setSizePolicy(sizePolicy);
        ctpActionLogin = new QAction(TraderGUIClass);
        ctpActionLogin->setObjectName(QStringLiteral("ctpActionLogin"));
        ctpActionLogout = new QAction(TraderGUIClass);
        ctpActionLogout->setObjectName(QStringLiteral("ctpActionLogout"));
        ltsActionLogin = new QAction(TraderGUIClass);
        ltsActionLogin->setObjectName(QStringLiteral("ltsActionLogin"));
        ltsActionLogout = new QAction(TraderGUIClass);
        ltsActionLogout->setObjectName(QStringLiteral("ltsActionLogout"));
        ibActionLogin = new QAction(TraderGUIClass);
        ibActionLogin->setObjectName(QStringLiteral("ibActionLogin"));
        ibActionLogout = new QAction(TraderGUIClass);
        ibActionLogout->setObjectName(QStringLiteral("ibActionLogout"));
        actionQuit = new QAction(TraderGUIClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        ctpActionConfig = new QAction(TraderGUIClass);
        ctpActionConfig->setObjectName(QStringLiteral("ctpActionConfig"));
        ltsActionConfig = new QAction(TraderGUIClass);
        ltsActionConfig->setObjectName(QStringLiteral("ltsActionConfig"));
        ibActionConfig = new QAction(TraderGUIClass);
        ibActionConfig->setObjectName(QStringLiteral("ibActionConfig"));
        centralWidget = new QWidget(TraderGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontal_splitter = new QSplitter(centralWidget);
        horizontal_splitter->setObjectName(QStringLiteral("horizontal_splitter"));
        horizontal_splitter->setOrientation(Qt::Horizontal);
        strategy_widget = new QWidget(horizontal_splitter);
        strategy_widget->setObjectName(QStringLiteral("strategy_widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(strategy_widget->sizePolicy().hasHeightForWidth());
        strategy_widget->setSizePolicy(sizePolicy2);
        horizontal_splitter->addWidget(strategy_widget);
        layoutWidget = new QWidget(horizontal_splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabMarket = new QTabWidget(layoutWidget);
        tabMarket->setObjectName(QStringLiteral("tabMarket"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabMarket->sizePolicy().hasHeightForWidth());
        tabMarket->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(tabMarket);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabLeft = new QTabWidget(layoutWidget);
        tabLeft->setObjectName(QStringLiteral("tabLeft"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tabLeft->sizePolicy().hasHeightForWidth());
        tabLeft->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(tabLeft);

        tabRight = new QTabWidget(layoutWidget);
        tabRight->setObjectName(QStringLiteral("tabRight"));
        sizePolicy4.setHeightForWidth(tabRight->sizePolicy().hasHeightForWidth());
        tabRight->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(tabRight);


        verticalLayout->addLayout(horizontalLayout);

        horizontal_splitter->addWidget(layoutWidget);

        gridLayout->addWidget(horizontal_splitter, 0, 0, 1, 1);

        TraderGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TraderGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 801, 23));
        menuGateway = new QMenu(menuBar);
        menuGateway->setObjectName(QStringLiteral("menuGateway"));
        menuCTP = new QMenu(menuGateway);
        menuCTP->setObjectName(QStringLiteral("menuCTP"));
        menuLST = new QMenu(menuGateway);
        menuLST->setObjectName(QStringLiteral("menuLST"));
        menuIB = new QMenu(menuGateway);
        menuIB->setObjectName(QStringLiteral("menuIB"));
        menuStrategy = new QMenu(menuBar);
        menuStrategy->setObjectName(QStringLiteral("menuStrategy"));
        menuRisk = new QMenu(menuBar);
        menuRisk->setObjectName(QStringLiteral("menuRisk"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        TraderGUIClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(TraderGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TraderGUIClass->setStatusBar(statusBar);

        menuBar->addAction(menuGateway->menuAction());
        menuBar->addAction(menuStrategy->menuAction());
        menuBar->addAction(menuRisk->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuGateway->addSeparator();
        menuGateway->addAction(menuCTP->menuAction());
        menuGateway->addAction(menuLST->menuAction());
        menuGateway->addAction(menuIB->menuAction());
        menuGateway->addSeparator();
        menuGateway->addAction(actionQuit);
        menuCTP->addAction(ctpActionLogin);
        menuCTP->addAction(ctpActionLogout);
        menuCTP->addAction(ctpActionConfig);
        menuLST->addAction(ltsActionLogin);
        menuLST->addAction(ltsActionLogout);
        menuLST->addAction(ltsActionConfig);
        menuIB->addAction(ibActionLogin);
        menuIB->addAction(ibActionLogout);
        menuIB->addAction(ibActionConfig);

        retranslateUi(TraderGUIClass);

        tabMarket->setCurrentIndex(-1);
        tabLeft->setCurrentIndex(-1);
        tabRight->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(TraderGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *TraderGUIClass)
    {
        TraderGUIClass->setWindowTitle(QApplication::translate("TraderGUIClass", "Trader", Q_NULLPTR));
        ctpActionLogin->setText(QApplication::translate("TraderGUIClass", "login", Q_NULLPTR));
        ctpActionLogout->setText(QApplication::translate("TraderGUIClass", "logout", Q_NULLPTR));
        ltsActionLogin->setText(QApplication::translate("TraderGUIClass", "login", Q_NULLPTR));
        ltsActionLogout->setText(QApplication::translate("TraderGUIClass", "logout", Q_NULLPTR));
        ibActionLogin->setText(QApplication::translate("TraderGUIClass", "login", Q_NULLPTR));
        ibActionLogout->setText(QApplication::translate("TraderGUIClass", "logout", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("TraderGUIClass", "Quit", Q_NULLPTR));
        ctpActionConfig->setText(QApplication::translate("TraderGUIClass", "config", Q_NULLPTR));
        ltsActionConfig->setText(QApplication::translate("TraderGUIClass", "config", Q_NULLPTR));
        ibActionConfig->setText(QApplication::translate("TraderGUIClass", "config", Q_NULLPTR));
        menuGateway->setTitle(QApplication::translate("TraderGUIClass", "\347\263\273\347\273\237", Q_NULLPTR));
        menuCTP->setTitle(QApplication::translate("TraderGUIClass", "CTP", Q_NULLPTR));
        menuLST->setTitle(QApplication::translate("TraderGUIClass", "LST", Q_NULLPTR));
        menuIB->setTitle(QApplication::translate("TraderGUIClass", "IB", Q_NULLPTR));
        menuStrategy->setTitle(QApplication::translate("TraderGUIClass", "\347\255\226\347\225\245\347\256\241\347\220\206", Q_NULLPTR));
        menuRisk->setTitle(QApplication::translate("TraderGUIClass", "\351\243\216\351\231\251\347\256\241\347\220\206", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("TraderGUIClass", "\345\205\263\344\272\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TraderGUIClass: public Ui_TraderGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRADERGUI_H
