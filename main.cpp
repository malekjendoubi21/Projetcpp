#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include "equipement.h"
#include "gestion_equipement.h"
#include "gestion_employe.h"
#include "login.h"
#include "menu.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu M;
    Connexion c;
    bool test=c.createconnect();
    if(test)
    {M.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
