#include "user.h"

#include <QString>
#include <QSqlQuery>
#include <QVariant>

bool User::signup(QString fname, QString lname, QString email, QString pass)
{
    QSqlQuery query(DB_Connection);

    if (!query.exec("CREATE TABLE IF NOT EXISTS user (id INTEGER PRIMARY KEY AUTOINCREMENT, fname TEXT, lname TEXT, email TEXT, pass TEXT)")) {
        qDebug() << "Error creating table:" << query.lastError().text();
        DB_Connection.close();
    }

    if (!query.prepare("INSERT INTO user(fname, lname, email, pass) VALUES(:fname, :lname, :email, :pass)")) {
        qDebug() << "Prepare error:" << query.lastError().text();
        DB_Connection.close();
    }

    query.bindValue(":fname", fname);
    query.bindValue(":lname", lname);
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);

    if (!query.exec()) {
        qDebug() << "Query error:" << query.lastError().text();
        DB_Connection.close();
        return false;
    } else {
        DB_Connection.commit();
        qDebug() << "User signed up successfully!";
        DB_Connection.close();

        this->fname = fname;
        this->lname = lname;
        this->email = email;
        this->pass = pass;

        return true;
    }
}

bool User::login(QString email, QString pass){
    QSqlQuery query(DB_Connection);
    query.prepare("SELECT * FROM user WHERE email = :email AND pass = :pass");
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);

    if (!query.exec() || !query.next()) {
        qDebug() << "Login failed. Invalid username or password!";
        return false;
    } else {
        qDebug() << "Login successful!";
        qDebug() << email << pass;

        this->fname = query.value("fname").toString();
        this->lname = query.value("lname").toString();
        this->email = query.value("email").toString();
        this->pass = query.value("pass").toString();
        this->role = query.value("role").toString();

        return true;
    }
}

QString User::getEmail(){
    qDebug() << this->email;
    return this->email;
}

QString User::getRole(){
    qDebug() << this->role;
    return this->role;
}

QString User::getFname(){
    return this->fname;
}

bool User::deleteUser(QString id){
    QSqlQuery query(DB_Connection);

    if (!query.prepare("DELETE FROM user WHERE id="+ id + "")) {
        qDebug() << "Prepare error:" << query.lastError().text();
        DB_Connection.close();
    }

    if (!query.exec()) {
        qDebug() << "Query error:" << query.lastError().text();
        DB_Connection.close();
        return false;
    } else {
        return true;
    }
}

bool User::updateUser(QString id, QString email, QString fname, QString lname, QString pass){
    QSqlQuery query(DB_Connection);

    if (!query.prepare("UPDATE user SET email=:email, fname=:fname, lname=:lname, pass=:pass WHERE id="+ id + "")) {
        qDebug() << "Prepare error:" << query.lastError().text();
        DB_Connection.close();
    }

    query.bindValue(":fname", fname);
    query.bindValue(":lname", lname);
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);

    if (!query.exec()) {
        qDebug() << "Query error:" << query.lastError().text();
        DB_Connection.close();
        return false;
    } else {
        return true;
    }
}
