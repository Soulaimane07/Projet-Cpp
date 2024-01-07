#include "deleteuser.h"
#include "ui_deleteuser.h"

#include "user.h"
#include "mainwindow.h"

deleteUser::deleteUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteUser)
{
    ui->setupUi(this);
}

deleteUser::~deleteUser()
{
    delete ui;
}

void deleteUser::on_Supprimer_clicked()
{
    QString id = ui->idLineEdit->text();

    if(id != ""){
        User user;
        if(user.deleteUser(id)){
            hide();

            QSqlQueryModel *modal = new QSqlQueryModel();
            QSqlQuery query(DB_Connection);

            query.prepare("SELECT * FROM user");
            query.exec();
            modal->setQuery(query);
        }
    } else {
        ui->error->setText("Les champs doivent être complétés !");
    }
}
