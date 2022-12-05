

#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QIntValidator>
#include "menu.h"




login::~login()
{
    delete ui;
}



   login::login(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::login)
{
    ui->setupUi(this);
}


void login::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
           QString password = ui->lineEdit_password->text();

           if ((username == "admin" && password == "admin")||(username == "aziz" && password == "aziz")) {
               QMessageBox::information(this, "Login", "Username and password are correct");



           }
           else {
               QMessageBox::warning(this, "Login", "Username and password are not correct");
           }

           ui->lineEdit_username->clear();
           ui->lineEdit_password->clear();
}
