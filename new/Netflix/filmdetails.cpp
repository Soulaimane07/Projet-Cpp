#include "filmdetails.h"
#include "ui_filmdetails.h"
#include "user.h"

filmDetails::filmDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filmDetails)
{
    ui->setupUi(this);
}

filmDetails::~filmDetails()
{
    delete ui;
}


bool filmDetails::filmOpen(int id)
{
    QSqlQuery query(DB_Connection);

    query.prepare("SELECT * FROM film WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        qDebug() << "--> Film not exist !";
        return false;
    } else {
        qDebug() << "--> Film exists !";
        qDebug() << query.value("title").toString();

        ui->label->setText(query.value("title").toString());
        ui->widget->setStyleSheet("background-image: url("+query.value("image").toString()+") 0 0 0 0; stretch stretch; background-repeat: no-repeat; background-position: center");
        ui->desc->setText(query.value("description").toString());
        ui->details->setText(query.value("genre").toString() + "  -  " +
                          query.value("duree").toString() + "min  -  " +
                          query.value("prix").toString() + "DH");
        ui->realisateur->setText("Realiser par: " + query.value("realisateur").toString());

        User user;
        qDebug() << "hh " + user.getEmail();

        return true;
    }
}
