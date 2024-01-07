#include "film.h"

#include <QString>
#include <QSqlQuery>
#include <QVariant>

bool Film::createFilm(QString title, int prix, QString realisateur, int duree, QString dateSortie, QString description, QString genre){
    //this->image = image;
    this->title = title;
    this->prix = prix;
    this->realisateur = realisateur;
    this->duree = duree;
    this->dateSortie = dateSortie;
    this->description = description;
    this->genre = genre;

    QSqlQuery query(DB_Connection);

    query.prepare("INSERT INTO film (image, title, prix, realisateur, duree, dateSortie, description, genre) VALUES (:image, :title, :prix, :realisateur, :duree, :dateSortie, :description, :genre)");
    query.bindValue(":title", title);
    query.bindValue(":image", image);
    query.bindValue(":prix", prix);
    query.bindValue(":realisateur", realisateur);
    query.bindValue(":duree", duree);
    query.bindValue(":dateSortie", dateSortie);
    query.bindValue(":description", description);
    query.bindValue(":genre", genre);

    if(!query.exec()){
        qDebug() << "Film not created!";
        return false;
    } else {
        qDebug() << "Film created!";
        return true;
    }
}

bool Film::getFilm(int id){
    QSqlQuery query(DB_Connection);

    query.prepare("SELECT * FROM film WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        qDebug() << "--> Film not exist !";
        return false;
    } else {
        qDebug() << "--> Film exists !";
        qDebug() << query.value("title").toString();

        this->id = query.value("id").toInt();
        this->image = query.value("image").toString();
        this->title = query.value("title").toString();
        this->prix = query.value("prix").toInt();
        this->genre = query.value("genre").toString();

        return true;
    }
}

QString Film::getImage(){
    return this->image;
}

QString Film::getTitle(){
    return this->title;
}

int Film::getPrix(){
    return this->prix;
}

QString Film::getGenre(){
    return this->genre;
}
