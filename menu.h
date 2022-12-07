#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow.h"
#include "gestion_employe.h"
#include "gestion_equipement.h"
#include "gestion_programme.h"
#include "dialog_invite.h"
namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_equipement_clicked();

    void on_pushButton_employe_clicked();



    void on_pushButton_Login_clicked();

    void on_pushButton_equipement_3_clicked();

    void on_pushButton_equipement_5_clicked();

public:
    Ui::menu *ui;
private:
    gestion_employe aziz;
    gestion_equipement imed;
    gestion_programme malek ;
    Dialog_invite wissem;
};

#endif // MENU_H
