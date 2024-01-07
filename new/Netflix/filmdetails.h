#ifndef FILMDETAILS_H
#define FILMDETAILS_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QtSql>

namespace Ui {
class filmDetails;
}

class filmDetails : public QDialog
{
    Q_OBJECT

public:
    explicit filmDetails(QWidget *parent = nullptr);
    ~filmDetails();
    bool filmOpen(int id);

public:
    Ui::filmDetails *ui;
    QSqlDatabase DB_Connection;
};

#endif // FILMDETAILS_H
