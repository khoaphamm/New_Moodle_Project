#include "studentwindow.h"
#include "ui_studentwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>

StudentWindow::StudentWindow(QWidget *parent)
    : QTabWidget(parent)
    , ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
    this->setTabBar(new CustomTabBar);
    this->setTabPosition(QTabWidget::West);

    // Set the height of the tab bar to match the height of the window
    // this->tabBar()->setFixedHeight(this->height());

    // // Set the width of the tabs
    // QString styleSheet = "QTabBar::tab {"
    //                     "width: 200px;"  // Set the width of the tabs
    //                     "}";
    
    // this->tabBar()->setStyleSheet(styleSheet);

    // Create the first tab
    QWidget *firstTabContent = new QWidget(this);
    int firstTabIndex = this->insertTab(0, firstTabContent, "First Tab");

    // Customize the first tab
    this->setTabText(firstTabIndex, "Custom First Tab");

    this->setTabToolTip(firstTabIndex, "This is the first tab");

    // Create the second tab
    QWidget *secondTabContent = new QWidget(this);
    int secondTabIndex = this->addTab(secondTabContent, "Second Tab");

    // Customize the second tab
    this->setTabText(secondTabIndex, "Custom Second Tab");

    this->setTabToolTip(secondTabIndex, "This is the second tab");
}

    CustomTabBar::CustomTabBar(QWidget *parent) : QTabBar(parent){// QVBoxLayout *layout = new QVBoxLayout(this);
        // layout->setSpacing(0);
        // layout->setContentsMargins(0, 0, 0, 0);

        // Add a spacer to the top of the layout
        // QSpacerItem *spacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
        // layout->addItem(spacer);

        // Create the actual tab bar
        // QTabBar *tabBar = new QTabBar(this);
        // layout->addWidget(tabBar);

        // // Create a new button
        QPushButton *profileButton = new QPushButton(this);
        profileButton->setText("Button");

        // Set the size and position of the button
        profileButton->setFixedSize(30, 30);
        profileButton->move(2, 2); // Adjust the position as needed
 }

QSize CustomTabBar::tabSizeHint(int index) const
{
    int tabHeight = 100;  // The height of each tab
    int tabWidth = this->width();  // The width of each tab

    // Return the size that the tab should occupy
    return QSize(tabWidth, tabHeight);
}

QRect CustomTabBar::tabRect(int index) const
{
    int tabHeight = 100;  // The height of each tab
    int tabWidth = this->width();  // The width of each tab

    // Calculate the y position of the tab
    int yPos = 50 + index * tabHeight;  // Add 50 pixels to the y position

    // Return the rectangle that the tab should occupy
    return QRect(0, yPos, tabWidth, tabHeight);
}

void StudentWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::warning( this, "Log Out",
                                                               tr("Are you sure?\n"),
                                                               QMessageBox::No | QMessageBox::Yes,
                                                               QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
    }
}

StudentWindow::~StudentWindow()
{
    delete ui;
}


