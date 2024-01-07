#ifndef CREATEFILM_H
#define CREATEFILM_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class CreateFilm;
}

class CreateFilm : public QDialog
{
    Q_OBJECT

public:
    explicit CreateFilm(QWidget *parent = nullptr);
    ~CreateFilm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CreateFilm *ui;
    QSqlDatabase DB_Connection;
};

#endif // CREATEFILM_H
