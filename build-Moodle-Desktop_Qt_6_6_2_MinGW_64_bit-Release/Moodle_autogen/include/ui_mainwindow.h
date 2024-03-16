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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QPushButton *pushButtonLogin;
    QLineEdit *lineEditPassword;
    QLabel *labelPlaceholder;
    QPushButton *pushButtonShowPassword;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(883, 630);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #F0F2F5"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(200, 180, 461, 361));
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: #FFFFFF"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 60, 401, 51));
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit { \n"
"	border: 1px solid rgb(212, 212, 212); \n"
"	border-radius: 10px; \n"
"	color: black; \n"
"	padding-left: 15px; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    color: black;\n"
"}"));
        lineEdit->setDragEnabled(false);
        pushButtonLogin = new QPushButton(groupBox);
        pushButtonLogin->setObjectName("pushButtonLogin");
        pushButtonLogin->setGeometry(QRect(30, 230, 401, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("VNI-Helve-Condense")});
        font.setPointSize(16);
        pushButtonLogin->setFont(font);
        pushButtonLogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0866FF;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: #0866FF;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #038EFF;\n"
"    border-color: #038EFF;\n"
"}\n"
"\n"
""));
        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(30, 130, 401, 51));
        lineEditPassword->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid rgb(212, 212, 212);\n"
"    border-radius: 10px;\n"
"    color: gray;\n"
"    padding-left: 15px;\n"
"	font-size: 12px; lineedit-password-character: 9679; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    color: black;\n"
"}"));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        labelPlaceholder = new QLabel(groupBox);
        labelPlaceholder->setObjectName("labelPlaceholder");
        labelPlaceholder->setGeometry(QRect(50, 140, 191, 31));
        labelPlaceholder->setStyleSheet(QString::fromUtf8("color: gray;"));
        pushButtonShowPassword = new QPushButton(groupBox);
        pushButtonShowPassword->setObjectName("pushButtonShowPassword");
        pushButtonShowPassword->setGeometry(QRect(390, 140, 31, 31));
        pushButtonShowPassword->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	border-radius: 15px; \n"
"	background-color: lightgray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-radius: 15px; \n"
"	background-color: gray;\n"
"}\n"
"\n"
""));
        lineEditPassword->raise();
        lineEdit->raise();
        pushButtonLogin->raise();
        labelPlaceholder->raise();
        pushButtonShowPassword->raise();
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, -70, 541, 241));
        label->setPixmap(QPixmap(QString::fromUtf8(":/loginpageAsset/FITLogo.png")));
        label->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 883, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonLogin, SIGNAL(clicked()), MainWindow, SLOT(on_button_clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("MainWindow", "Log in", nullptr));
        lineEditPassword->setText(QString());
        lineEditPassword->setPlaceholderText(QString());
        labelPlaceholder->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButtonShowPassword->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
