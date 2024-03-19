#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFontDatabase>
#include "Course.h"
#include <string>

class MainWindow;

namespace Ui {
class StudentView;
}

class StudentView : public QMainWindow
{
    Q_OBJECT

public:

    std::string StudentID;
    LinkedList<Course> thisStudentCourse;

    explicit StudentView(MainWindow* mainWindow, QWidget *parent = nullptr, std::string StudentID = "");
    ~StudentView();
    void closeEvent(QCloseEvent *event);
    void setStudent(std::string StudentID);  // Method to set the student
    void setupPage();  // Method to set up the page
    QString loadFont(const QString &resourcePath);  // Method to load the font
    void setUpCourseList();  // Method to set up the course list

private slots:
    void on_actionExit_triggered(QCloseEvent *event);
    void on_stackedWidget_currentChanged(int index);
    void on_profile_btn1_toggled();
    void on_profile_btn2_toggled();
    void on_course_btn1_toggled();
    void on_course_btn2_toggled();
    void on_grade_btn1_toggled();
    void on_grade_btn2_toggled();


private:
    Ui::StudentView *ui;
    MainWindow* mainWindow;
};

#endif // STUDENTVIEW_H
