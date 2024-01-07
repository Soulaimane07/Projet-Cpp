#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class deleteUser;
}

class deleteUser : public QDialog
{
    Q_OBJECT

public:
    explicit deleteUser(QWidget *parent = nullptr);
    ~deleteUser();

private slots:
    void on_Supprimer_clicked();

private:
    Ui::deleteUser *ui;
    QSqlDatabase DB_Connection;
};

#endif // DELETEUSER_H
