#ifndef FILM_H
#define FILM_H

#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QtSql>

class Film
{
public:
    bool createFilm(QString title, int prix, QString realisateur, int duree, QString dateSortie, QString description, QString genre);
    bool getFilm(int id);
    QString getImage();
    QString getTitle();
    QString getGenre();
    int getPrix();

public:
    int id;
    QString image;
    QString title;
    int prix;
    QString realisateur;
    int duree;
    QString genre;
    QString dateSortie;
    QString description;
    QSqlDatabase DB_Connection;
};

#endif // FILM_H
