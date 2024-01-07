#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "film.h"
#include "createfilm.h"
#include "deleteuser.h"
#include "updateuser.h"
#include "filmdetails.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
        ui->setupUi(this);

        DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
        DB_Connection.setHostName("localhost");
        DB_Connection.setDatabaseName("netflixDB.db");

        if(DB_Connection.open()){
            qDebug() << "--> Database is connected !";
        } else {
            qDebug() << "--> Database is not connected !";
            qDebug() << "--> Error: " << DB_Connection.lastError();
        }



        ui->ajouterFilm->setVisible(false);

        ui->widget->setVisible(false);
        ui->widget_2->setVisible(false);
        ui->widget_3->setVisible(false);
        ui->widget_4->setVisible(false);
        ui->widget_5->setVisible(false);
        ui->widget_6->setVisible(false);
        ui->widget_7->setVisible(false);
        ui->widget_8->setVisible(false);
        ui->widget_9->setVisible(false);
        ui->widget_10->setVisible(false);
        ui->widget_11->setVisible(false);
        ui->widget_12->setVisible(false);
        ui->pushButton_4->setVisible(true);
        ui->pushButton_5->setVisible(false);

        ui->film1Title->setVisible(false);
        ui->film1Price->setVisible(false);
        ui->details1->setVisible(false);
        ui->film2Title->setVisible(false);
        ui->film2Price->setVisible(false);
        ui->details2->setVisible(false);
        ui->film3Title->setVisible(false);
        ui->film3Price->setVisible(false);
        ui->details3->setVisible(false);
        ui->film4Title->setVisible(false);
        ui->film4Price->setVisible(false);
        ui->details4->setVisible(false);
        ui->film5Title->setVisible(false);
        ui->film5Price->setVisible(false);
        ui->details5->setVisible(false);
        ui->film6Title->setVisible(false);
        ui->film6Price->setVisible(false);
        ui->details6->setVisible(false);
        ui->film7Title->setVisible(false);
        ui->film7Price->setVisible(false);
        ui->details7->setVisible(false);
        ui->film8Title->setVisible(false);
        ui->film8Price->setVisible(false);
        ui->details8->setVisible(false);
        ui->film9Title->setVisible(false);
        ui->film9Price->setVisible(false);
        ui->details9->setVisible(false);
        ui->film10Title->setVisible(false);
        ui->film10Price->setVisible(false);
        ui->details10->setVisible(false);
        ui->film11Title->setVisible(false);
        ui->film11Price->setVisible(false);
        ui->details11->setVisible(false);
        ui->film12Title->setVisible(false);
        ui->film12Price->setVisible(false);
        ui->details12->setVisible(false);



        //ui->widget->setStyleSheet("background-image: url(:/new/prefix1/C:/Users/Soulaimane/OneDrive/Desktop/grizzy.jpg) 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");

        Film film1;
        if(film1.getFilm(1)){
            ui->widget->setVisible(true);
            ui->film1Title->setVisible(true);
            ui->film1Price->setVisible(true);
            ui->details1->setVisible(true);

            ui->widget->setStyleSheet("background-image: url("+film1.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film1Title->setText(film1.getTitle());
            ui->film1Price->setText(QString::number(film.getPrix()) + "DH  -  " + film1.getGenre());
        }

        Film film2;
        if(film2.getFilm(2)){
            ui->widget_2->setVisible(true);
            ui->film2Title->setVisible(true);
            ui->film2Price->setVisible(true);
            ui->details2->setVisible(true);

            ui->widget_2->setStyleSheet("background-image: url("+film2.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film2Title->setText(film2.getTitle());
            ui->film2Price->setText(QString::number(film2.getPrix()) + "DH  -  " + film2.getGenre());
        }


        Film film3;
        if(film3.getFilm(3)){
            ui->widget_3->setVisible(true);
            ui->film3Title->setVisible(true);
            ui->film3Price->setVisible(true);
            ui->details3->setVisible(true);

            ui->widget_3->setStyleSheet("background-image: url("+film3.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film3Title->setText(film3.getTitle());
            ui->film3Price->setText(QString::number(film3.getPrix()) + "DH  -  " + film3.getGenre());
        }

        Film film4;
        if(film4.getFilm(4)){
            ui->widget_4->setVisible(true);
            ui->film4Title->setVisible(true);
            ui->film4Price->setVisible(true);
            ui->details4->setVisible(true);

            ui->widget_4->setStyleSheet("background-image: url("+film4.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film4Title->setText(film4.getTitle());
            ui->film4Price->setText(QString::number(film4.getPrix()) + "DH  -  " + film4.getGenre());
        }

        Film film5;
        if(film5.getFilm(5)){
            ui->widget_5->setVisible(true);
            ui->film5Title->setVisible(true);
            ui->film5Price->setVisible(true);
            ui->details5->setVisible(true);

            ui->widget_5->setStyleSheet("background-image: url("+film5.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film5Title->setText(film5.getTitle());
            ui->film5Price->setText(QString::number(film5.getPrix()) + "DH  -  " + film5.getGenre());
        }

        Film film6;
        if(film6.getFilm(6)){
            ui->widget_6->setVisible(true);
            ui->film6Title->setVisible(true);
            ui->film6Price->setVisible(true);
            ui->details6->setVisible(true);

            ui->widget_6->setStyleSheet("background-image: url("+film6.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film6Title->setText(film6.getTitle());
            ui->film6Price->setText(QString::number(film6.getPrix()) + "DH  -  " + film6.getGenre());
        }

        Film film7;
        if(film7.getFilm(7)){
            ui->widget_7->setVisible(true);
            ui->film7Title->setVisible(true);
            ui->film7Price->setVisible(true);
            ui->details7->setVisible(true);

            ui->widget_7->setStyleSheet("background-image: url("+film7.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film7Title->setText(film7.getTitle());
            ui->film7Price->setText(film7.getGenre());
            ui->film7Price->setText(QString::number(film7.getPrix()) + "DH  -  " + film7.getGenre());
        }

        Film film8;
        if(film8.getFilm(8)){
            ui->widget_8->setVisible(true);
            ui->film8Title->setVisible(true);
            ui->film8Price->setVisible(true);
            ui->details8->setVisible(true);

            ui->widget_8->setStyleSheet("background-image: url("+film8.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film8Title->setText(film8.getTitle());
            ui->film8Price->setText(QString::number(film8.getPrix()) + "DH  -  " + film8.getGenre());
        }

        Film film9;
        if(film9.getFilm(9)){
            ui->widget_9->setVisible(true);
            ui->film9Title->setVisible(true);
            ui->film9Price->setVisible(true);
            ui->details9->setVisible(true);

            ui->widget_9->setStyleSheet("background-image: url("+film9.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film9Title->setText(film9.getTitle());
            ui->film9Price->setText(QString::number(film9.getPrix()) + "DH  -  " + film9.getGenre());
        }

        Film film10;
        if(film10.getFilm(10)){
            ui->widget_10->setVisible(true);
            ui->film10Title->setVisible(true);
            ui->film10Price->setVisible(true);
            ui->details10->setVisible(true);

            ui->widget_10->setStyleSheet("background-image: url("+film10.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film10Title->setText(film10.getTitle());
            ui->film10Price->setText(QString::number(film10.getPrix()) + "DH  -  " + film10.getGenre());
        }

        Film film11;
        if(film11.getFilm(11)){
            ui->widget_11->setVisible(true);
            ui->film11Title->setVisible(true);
            ui->film11Price->setVisible(true);
            ui->details11->setVisible(true);

            ui->widget_11->setStyleSheet("background-image: url("+film11.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
            ui->film11Title->setText(film11.getTitle());
            ui->film11Price->setText(QString::number(film11.getPrix()) + "DH  -  " + film11.getGenre());
        }

        Film film12;
        if(film12.getFilm(12)){
        ui->widget_12->setVisible(true);
        ui->film12Title->setVisible(true);
        ui->film12Price->setVisible(true);
        ui->details12->setVisible(true);

        ui->widget_12->setStyleSheet("background-image: url("+film12.getImage()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
        ui->film12Title->setText(film12.getTitle());
        ui->film12Price->setText(QString::number(film12.getPrix()) + "DH  -  " + film12.getGenre());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_commandLinkButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_loginBtn_clicked()
{
    QString email = ui->emailLine->text();
    QString pass = ui->passLine->text();

    if(email == "" || pass == ""){
        ui->loginError->setText("l'email et le mot de passe doivent être renseignés !");
    } else {
        User user;

        if(user.login(email, pass)){
            ui->stackedWidget->setCurrentIndex(3);
            ui->bienvenue->setText("Bienvenue " + user.getFname());
            if(user.getRole() == "admin"){
                ui->ajouterFilm->setVisible(true);
                ui->pushButton_4->setVisible(false);
                ui->pushButton_5->setVisible(true);
            }
        } else {
            ui->loginError->setText("l'email ou le mot de passe sont incorrects !");
        }
    }
}

void MainWindow::on_signupBtn_clicked()
{
    QString fname = ui->prNomLineEdit->text();
    QString lname = ui->nomLineEdit->text();
    QString email = ui->emailLineEdit_2->text();
    QString pass = ui->motDePasseLineEdit_2->text();

    if(fname == "" || lname == "" || email == "" || pass == ""){
        ui->signupError->setText("les informations doivent être renseignéss !");
    } else {
        User user;
        if(user.signup(fname, lname, email, pass)){
            ui->stackedWidget->setCurrentIndex(3);
            ui->bienvenue->setText("Bienvenue " + user.getFname());
        } else {
            ui->signupError->setText("les informations sont incorrects !");
        }
    }
}

void MainWindow::on_logoutBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ajouterFilm_clicked()
{
    CreateFilm CreateFilm;
    CreateFilm.setModal(true);
    CreateFilm.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query(DB_Connection);

    query.prepare("SELECT * FROM user");
    query.exec();
    modal->setQuery(query);
    ui->tableView->setModel(modal);

    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_10_clicked()
{
    deleteUser deleteUser;
    deleteUser.setModal(true);
    deleteUser.exec();
}

void MainWindow::on_pushButton_11_clicked()
{
    updateUser updateUser;
    updateUser.setModal(true);
    updateUser.exec();
}





void MainWindow::on_details1_clicked()
{
    filmDetails filmDetails;
    if(filmDetails.filmOpen(1)){
        filmDetails.setModal(true);
        filmDetails.exec();
    }
}
