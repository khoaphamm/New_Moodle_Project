#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QMainWindow>

namespace Ui {
class StudentView;
}

class StudentView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentView(QWidget *parent = nullptr);
    ~StudentView();
    void closeEvent(QCloseEvent *event);

private:
    Ui::StudentView *ui;
};

#endif // STUDENTVIEW_H
