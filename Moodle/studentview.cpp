#include "studentview.h"
#include "ui_studentview.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>


StudentView::StudentView(MainWindow* mainWindow, QWidget *parent, std::string StudentID)
    : QMainWindow(parent)
    , mainWindow(mainWindow)
    , ui(new Ui::StudentView)
    , StudentID(StudentID)

{
    ui->setupUi(this);
    connect(ui->exitButton, &QPushButton::clicked, this, &StudentView::close);
    setStudent(StudentID);

    for (int i = 0; i < thisStudentCourse.size(); i++) {
        ui->courseList->addItem(QString::fromStdString(thisStudentCourse.get(i).courseInfo.courseID));
    }

}

void StudentView::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::warning(this, "Warning", "Are you sure you want to exit?",
                                   QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        QMainWindow::closeEvent(event);
        parentWidget()->show(); // Show the MainWindow
    } else if (ret == QMessageBox::No) {
        event->ignore(); // Ignore the close event
    }
}

void StudentView::setStudent(std::string StudentID){
    LinkedList<SchoolYear> schoolYears = mainWindow->SchoolYears;
    for (int i = 0; i < schoolYears.size(); i++) {
        LinkedList<Semester> semesters = schoolYears.get(i).semesters;
        for(int j = 0; j < semesters.size(); j++){
            LinkedList<Course> courses = semesters.get(j).courses;
            for (int k = 0; k < courses.size(); k++) {
                LinkedList<Student> students = courses.get(k).students;
                for (int h = 0; h < students.size(); h++) {
                    if (students.get(h).studentID == StudentID) {
                        thisStudentCourse.add(courses.get(k));
                    }
                }
            }
        }
    }
}


StudentView::~StudentView()
{
    delete ui;
}


