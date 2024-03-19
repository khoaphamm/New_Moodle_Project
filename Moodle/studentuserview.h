#ifndef STUDENTUSERVIEW_H
#define STUDENTUSERVIEW_H

#include <QTabWidget>

namespace Ui {
class StudentUserView;
}

class StudentUserView : public QTabWidget
{
    Q_OBJECT

public:
    explicit StudentUserView(QWidget *parent = nullptr);
    ~StudentUserView();

private:
    Ui::StudentUserView *ui;
};

#endif // STUDENTUSERVIEW_H
