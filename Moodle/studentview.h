#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QMainWindow>
#include "Student.h" 
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

private:
    Ui::StudentView *ui;
    MainWindow* mainWindow;
};

#endif // STUDENTVIEW_H
