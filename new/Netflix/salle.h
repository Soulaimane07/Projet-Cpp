#ifndef SALLE_H
#define SALLE_H


#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QtSql>

class salle
{
public:
    bool createSalle(int capacite, QString statut);
    bool getSalle(int id);

public:
    int id;
    int capacite;
    QString statut;
};

#endif // SALLE_H
