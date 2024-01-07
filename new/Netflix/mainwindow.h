#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "user.h"
#include "film.h"
#include <QMainWindow>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_loginBtn_clicked();

    void on_signupBtn_clicked();

    void on_logoutBtn_clicked();

    void on_ajouterFilm_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_details1_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB_Connection;
    User user;
    Film film;
};

#endif // MAINWINDOW_H
