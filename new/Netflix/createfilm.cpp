#include "createfilm.h"
#include "ui_createfilm.h"
#include "film.h"
#include <QFileDialog>
#include <QImage>
#include <QVector>
#include <QQueue>

CreateFilm::CreateFilm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateFilm)
{
    ui->setupUi(this);

    //DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    //DB_Connection.setHostName("localhost");
    //DB_Connection.setDatabaseName("netflixDB.db");

    //if(DB_Connection.open()){
    //    qDebug() << "--> Database is connected !";
    //} else {
    //    qDebug() << "--> Database is not connected !";
    //    qDebug() << "--> Error: " << DB_Connection.lastError();
    //}
}

CreateFilm::~CreateFilm()
{
    delete ui;
}

void CreateFilm::on_pushButton_clicked()
{
    QString title = ui->titreLineEdit->text();
    int prix = ui->prixLineEdit->text().toInt();
    QString realisateur = ui->realisateurLineEdit->text();
    int duree = ui->dureeLineEdit->text().toInt();
    QString dateSortie = ui->dateDeSortieDateEdit->text();
    QString description = ui->descriptionLineEdit->text();
    QString genre = ui->genreLineEdit->text();

    if(title != "" && prix != NULL && realisateur != "" && duree != NULL && dateSortie != "" && description != "" && genre != ""){
        //QImage img(fileName);

        Film film;
        if(film.createFilm(title, prix, realisateur, duree, dateSortie, description, genre)){
            hide();
        }
    } else {
        ui->error->setText("Les champs doivent être complétés !");
    }

}

void CreateFilm::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.png *.xpm *.jpg)"));
}
