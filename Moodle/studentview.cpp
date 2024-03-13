#include "studentview.h"
#include "ui_studentview.h"
#include <QMessageBox>
#include <QCloseEvent>


StudentView::StudentView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentView)
{
    ui->setupUi(this);
    connect(ui->exitButton, &QPushButton::clicked, this, &StudentView::close);
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

StudentView::~StudentView()
{
    delete ui;
}


