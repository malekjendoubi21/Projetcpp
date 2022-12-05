#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>
#include <QSound>
#include"mainwindow.h"


menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    setWindowTitle("MENU");

    ui->stackedWidget->setCurrentIndex(0);
}

menu::~menu()
{
    delete ui;
}



void menu::on_pushButton_equipement_clicked()
{

    QMessageBox::information(nullptr, QObject::tr("Gestion Equipement"),
                                    QObject::tr("Welcome Imed."), QMessageBox::Ok);
     imed.show();
}

void menu::on_pushButton_employe_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Gestion Employe"),
                                    QObject::tr("Welcome Aziz."), QMessageBox::Ok);
     aziz.show();
}

void menu::on_pushButton_Login_clicked()
{

        QString username = ui->lineEdit_username->text();
               QString password = ui->lineEdit_password->text();

               if ((username == "admin" && password == "admin")||(username == "aziz" && password == "aziz")) {
                   QMessageBox::information(this, "Login", "Username and password are correct");

                   ui->stackedWidget->setCurrentIndex(1);


               }
               else {
                   QMessageBox::warning(this, "Login", "Username and password are not correct");
               }

               ui->lineEdit_username->clear();
               ui->lineEdit_password->clear();

}
