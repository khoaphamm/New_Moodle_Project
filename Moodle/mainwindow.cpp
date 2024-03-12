#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
        QMessageBox::information(this, "Login", "Login successful!");
    } else {
        // Login failed
        QMessageBox::warning(this, "Login", "Username or password is incorrect.");
    }
}

