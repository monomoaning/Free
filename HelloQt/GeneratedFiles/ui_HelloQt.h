/********************************************************************************
** Form generated from reading UI file 'HelloQt.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOQT_H
#define UI_HELLOQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelloQtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HelloQtClass)
    {
        if (HelloQtClass->objectName().isEmpty())
            HelloQtClass->setObjectName(QStringLiteral("HelloQtClass"));
        HelloQtClass->resize(600, 400);
        menuBar = new QMenuBar(HelloQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        HelloQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HelloQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HelloQtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(HelloQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        HelloQtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(HelloQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HelloQtClass->setStatusBar(statusBar);

        retranslateUi(HelloQtClass);

        QMetaObject::connectSlotsByName(HelloQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *HelloQtClass)
    {
        HelloQtClass->setWindowTitle(QApplication::translate("HelloQtClass", "HelloQt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelloQtClass: public Ui_HelloQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOQT_H
