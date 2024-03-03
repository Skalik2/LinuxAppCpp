/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonSubmit;
    QLineEdit *lineEditLogin;
    QLabel *labelLogin;
    QLineEdit *lineEditPassword;
    QLabel *labelPassword;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButtonSubmit = new QPushButton(centralwidget);
        pushButtonSubmit->setObjectName("pushButtonSubmit");
        pushButtonSubmit->setGeometry(QRect(350, 440, 83, 29));
        lineEditLogin = new QLineEdit(centralwidget);
        lineEditLogin->setObjectName("lineEditLogin");
        lineEditLogin->setGeometry(QRect(170, 180, 113, 28));
        labelLogin = new QLabel(centralwidget);
        labelLogin->setObjectName("labelLogin");
        labelLogin->setGeometry(QRect(170, 150, 63, 20));
        lineEditPassword = new QLineEdit(centralwidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(170, 260, 113, 28));
        labelPassword = new QLabel(centralwidget);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(170, 230, 63, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 440, 83, 29));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(310, 400, 83, 29));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonSubmit->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        labelLogin->setText(QCoreApplication::translate("MainWindow", "Login:", nullptr));
        labelPassword->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
