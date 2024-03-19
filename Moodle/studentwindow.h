#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QTabWidget>
#include <QTabBar>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class StudentWindow;
}

class CustomTabBar : public QTabBar {

    Q_OBJECT

public:
    CustomTabBar(QWidget *parent = nullptr);
    QSize tabSizeHint(int index) const override;
    QRect tabRect(int index) const;
};

class StudentWindow : public QTabWidget
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = nullptr);
    ~StudentWindow();
    void closeEvent(QCloseEvent *event);

private:
    Ui::StudentWindow *ui;
};

#endif // STUDENTWINDOW_H
