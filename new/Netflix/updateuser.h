#ifndef UPDATEUSER_H
#define UPDATEUSER_H

#include <QDialog>

namespace Ui {
class updateUser;
}

class updateUser : public QDialog
{
    Q_OBJECT

public:
    explicit updateUser(QWidget *parent = nullptr);
    ~updateUser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::updateUser *ui;
};

#endif // UPDATEUSER_H
