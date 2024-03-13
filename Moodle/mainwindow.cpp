#include "mainwindow.h"
#include "studentview.h"
#include "./ui_mainwindow.h"
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
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    ui->lineEdit_2->setFont(font2);


    // QFontMetrics fm(font2);
    // QString elidedText = fm.elidedText("Password", Qt::ElideRight, ui->lineEdit_2->width());
    // ui->lineEdit_2->setPlaceholderText(elidedText);




    // for placeholder Qlabel
    font2.setPointSize(15);
    ui->labelPlaceholder->setFont(font2);
    palette = ui->labelPlaceholder->palette();
    palette.setColor(QPalette::WindowText, Qt::gray);
    ui->labelPlaceholder->setPalette(palette);
    ui->labelPlaceholder->setAttribute(Qt::WA_TransparentForMouseEvents); // Make it click-through-able


    //Enter to login
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_pushButtonLogin_clicked);
    connect(ui->lineEdit_2, &QLineEdit::returnPressed, this, &MainWindow::on_pushButtonLogin_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (username == "admin" && password == "password") {
        // Login successful
        StudentView* studentView = new StudentView(this);
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




void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->lineEdit_2->setStyleSheet("QLineEdit { border: 1px solid rgb(212, 212, 212); border-radius: 10px; color: black; padding-left: 15px; }");
    ui->labelPlaceholder->setVisible(arg1.isEmpty());

}

void MainWindow::on_lineEdit_2_focusChanged(bool hasFocus)
{
    ui->labelPlaceholder->setVisible(!hasFocus && ui->lineEdit_2->text().isEmpty());
}
