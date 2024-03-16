/********************************************************************************
** Form generated from reading UI file 'studentview.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTVIEW_H
#define UI_STUDENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentView
{
public:
    QWidget *centralwidget;
    QPushButton *courseButton;
    QPushButton *scoreboardButton;
    QPushButton *exitButton;
    QListWidget *courseList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentView)
    {
        if (StudentView->objectName().isEmpty())
            StudentView->setObjectName("StudentView");
        StudentView->resize(902, 633);
        StudentView->setStyleSheet(QString::fromUtf8("background-color: #F0F2F5"));
        centralwidget = new QWidget(StudentView);
        centralwidget->setObjectName("centralwidget");
        courseButton = new QPushButton(centralwidget);
        courseButton->setObjectName("courseButton");
        courseButton->setGeometry(QRect(20, 0, 271, 271));
        courseButton->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	border: 3px solid #0866FF; \n"
"}"));
        scoreboardButton = new QPushButton(centralwidget);
        scoreboardButton->setObjectName("scoreboardButton");
        scoreboardButton->setGeometry(QRect(310, 0, 271, 271));
        scoreboardButton->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	border: 3px solid #0866FF; \n"
"}"));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(600, 0, 281, 271));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	border: 3px solid #0866FF; \n"
"}"));
        courseList = new QListWidget(centralwidget);
        courseList->setObjectName("courseList");
        courseList->setGeometry(QRect(290, 280, 256, 192));
        StudentView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StudentView);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 902, 26));
        StudentView->setMenuBar(menubar);
        statusbar = new QStatusBar(StudentView);
        statusbar->setObjectName("statusbar");
        StudentView->setStatusBar(statusbar);

        retranslateUi(StudentView);

        QMetaObject::connectSlotsByName(StudentView);
    } // setupUi

    void retranslateUi(QMainWindow *StudentView)
    {
        StudentView->setWindowTitle(QCoreApplication::translate("StudentView", "MainWindow", nullptr));
        courseButton->setText(QCoreApplication::translate("StudentView", "View Courses", nullptr));
        scoreboardButton->setText(QCoreApplication::translate("StudentView", "Scoreboard", nullptr));
        exitButton->setText(QCoreApplication::translate("StudentView", "Exit ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentView: public Ui_StudentView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTVIEW_H
