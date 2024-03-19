#include "studentuserview.h"
#include "ui_studentuserview.h"

StudentUserView::StudentUserView(QWidget *parent)
    : QTabWidget(parent)
    , ui(new Ui::StudentUserView)
{
    ui->setupUi(this);
    QWidget *tab = new QWidget(this);
    this->addTab(tab, "Tab 1");
}

StudentUserView::~StudentUserView()
{
    delete ui;
}
