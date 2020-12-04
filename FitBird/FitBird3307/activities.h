#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include <QDialog>

namespace Ui {
class Activities;
}

class Activities : public QDialog
{
    Q_OBJECT

public:
    explicit Activities(QWidget *parent = nullptr);
    ~Activities();

private slots:
    void on_pushButton_addActivity_clicked();

private:
    Ui::Activities *ui;
};

#endif // ACTIVITIES_H
