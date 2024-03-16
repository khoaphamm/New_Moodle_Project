#include "mainwindow.h"
#include "studentview.h"
#include "./ui_mainwindow.h"
#include "Course.h"
#include "Student.h"
#include <QMessageBox>
#include <QFontDatabase>
#include <QPalette>
#include <QGraphicsDropShadowEffect>

QString loadFont(const QString &resourcePath) {
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , SchoolYears()
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupPage();
    

    Student student = Student("23125061", "Pham", "Khoa", "", "", "");

    Course course = Course("CS162", "Introduction to Programming", "", "", "", 0, "");
    Course course2 = Course("MTH252", "Calculus II", "", "", "", 0, "");

    Semester semester = Semester("Fall");

    course.addStudent(student);  
    course2.addStudent(student);  

    semester.addCourse(course);  
    semester.addCourse(course2);  

    SchoolYear year = SchoolYear("2023-2024");
    year.addSemester(semester);

    this->SchoolYears.add(year);
}

MainWindow::~MainWindow()
{
    // Iterate over all SchoolYear objects in SchoolYears
    while (!SchoolYears.isEmpty()) {
        SchoolYear year = SchoolYears.removeFirst();

        // Iterate over all Semester objects in each SchoolYear
        while (!year.semesters.isEmpty()) {
            Semester semester = year.semesters.removeFirst();

            // Iterate over all Course objects in each Semester
            while (!semester.courses.isEmpty()) {
                Course course = semester.courses.removeFirst();

                // Iterate over all Student objects in each Course
                while (!course.students.isEmpty()) {
                    course.students.removeFirst();
                }
            }
        }
    }

    
    delete ui;
}

void MainWindow::setupPage(){
    QString font1Family = loadFont(":/font/Helvetica Neue/HelveticaNeue-Bold.otf");
    QString font2Family = loadFont(":/font/HelveticaWorld-Regular.ttf");

    //Group box
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(20); // Adjust the blur radius
    effect->setOffset(0, 0); // Adjust the offset
    ui->groupBox->setGraphicsEffect(effect);


    //Log in button

    QFont font1(font1Family);
    font1.setPointSize(15);
    ui->pushButtonLogin->setFont(font1);
    QPalette palette = ui->pushButtonLogin->palette();
    palette.setColor(QPalette::ButtonText, Qt::white); // Set the color of the font
    ui->pushButtonLogin->setPalette(palette);

    //Description part

    QFont font2(font2Family);
    font2.setPointSize(15);
    //ui->label_2->setFont(font2);

    //Username line

    ui->lineEdit->setPlaceholderText("Username");
    ui->lineEdit->setFont(font2);

    // Password line

    font2.setPointSize(12);
    ui->lineEditPassword->setFont(font2);

    // Set the initial icon
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->pushButtonShowPassword->setIcon(QIcon(":/loginpageAsset/hide.png"));

    // Connect the clicked signal to a slot
    connect(ui->pushButtonShowPassword, &QPushButton::clicked, this, &MainWindow::togglePasswordVisibility);
    connect(ui->lineEditPassword, &QLineEdit::returnPressed, this, &MainWindow::on_pushButtonLogin_clicked);

    // for placeholder Qlabel
    font2.setPointSize(15);
    ui->labelPlaceholder->setFont(font2);
    palette = ui->labelPlaceholder->palette();
    palette.setColor(QPalette::WindowText, Qt::gray);
    ui->labelPlaceholder->setPalette(palette);
    ui->labelPlaceholder->setAttribute(Qt::WA_TransparentForMouseEvents); // Make it click-through-able

    //Enter to login
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_pushButtonLogin_clicked);
    connect(ui->lineEditPassword, &QLineEdit::returnPressed, this, &MainWindow::on_pushButtonLogin_clicked);
}

void MainWindow::on_pushButtonLogin_clicked()
{
    std::string username = ui->lineEdit->text().toStdString();
    std::string password = ui->lineEditPassword->text().toStdString();

    if (username == "23125061" && password == "password") {
        // Login successful
        StudentView* studentView = new StudentView(this, this, username);
        studentView->show();
        this->hide(); // Hide the MainWindow
    } else {
        // Login failed
        QMessageBox::warning(this, "Login", "Username or password is incorrect.");
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->lineEdit->setStyleSheet("QLineEdit { border: 1px solid rgb(212, 212, 212); border-radius: 10px; color: black; padding-left: 15px; }");
}




void MainWindow::on_lineEditPassword_textChanged(const QString &arg1)
{
    ui->lineEditPassword->setStyleSheet("QLineEdit { border: 1px solid rgb(212, 212, 212); border-radius: 10px; color: black; padding-left: 15px; }");
    ui->labelPlaceholder->setVisible(arg1.isEmpty());

}

void MainWindow::on_lineEditPassword_focusChanged(bool hasFocus)
{
    ui->labelPlaceholder->setVisible(!hasFocus && ui->lineEditPassword->text().isEmpty());
}

void MainWindow::togglePasswordVisibility()
{
    QFont font = ui->lineEditPassword->font();
    if (ui->lineEditPassword->echoMode() == QLineEdit::Password) {
        // The password is hidden, show it and set the "hide" icon
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);
        ui->pushButtonShowPassword->setIcon(QIcon(":/loginpageAsset/show.png"));
        font.setPointSize(15); // Set the font size to 15
    } else {
        // The password is shown, hide it and set the "unhide" icon
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
        ui->pushButtonShowPassword->setIcon(QIcon(":/loginpageAsset/hide.png"));
        font.setPointSize(12); // Set the font size back to 12
    }
    ui->lineEditPassword->setFont(font); // Apply the font changes
}
