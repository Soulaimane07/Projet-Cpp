#include "updateuser.h"
#include "ui_updateuser.h"
#include "user.h"

updateUser::updateUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateUser)
{
    ui->setupUi(this);
}

updateUser::~updateUser()
{
    delete ui;
}

void updateUser::on_pushButton_clicked()
{
    QString id = ui->idLineEdit->text();
    QString email = ui->adresseEMailLineEdit->text();
    QString fname = ui->prNomLineEdit->text();
    QString lname = ui->nomLineEdit->text();
    QString pass = ui->motDePasseLineEdit->text();

    if(id != "" && email != "" && fname != "" && lname != "" && pass != ""){
        User user;

        if(user.updateUser(id, email, fname, lname, pass)){
            hide();
        }
    } else {
        ui->label->setText("Les champs doivent être complétés !");
    }
}
