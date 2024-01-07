#ifndef USER_H
#define USER_H

#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QtSql>

class User
{
public:
    bool signup(QString fname, QString lname, QString email, QString pass);
    bool login(QString email, QString pass);
    QString getEmail();
    QString getRole();
    QString getFname();
    bool deleteUser(QString id);
    bool updateUser(QString id, QString email, QString fname, QString lname, QString pass);
    //~User();

public:
    QString fname;
    QString lname;
    QString email;
    QString pass;
    QString role;
    QSqlDatabase DB_Connection;
};

#endif // USER_H
