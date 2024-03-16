#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LinkedList.h"
#include "SchoolYear.h"
#include "Student.h"
#include "Course.h"
#include "Semester.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    LinkedList<SchoolYear> SchoolYears;
    ~MainWindow();

private slots:
    void on_pushButtonLogin_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEditPassword_textChanged(const QString &arg1);

    void on_lineEditPassword_focusChanged(bool hasFocus);

    void togglePasswordVisibility();

    void setupPage();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
