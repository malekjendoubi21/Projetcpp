#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
MainWindow w;
    connexion c;
    bool test=c.createconnect();
    if(test)
    {


        c.createconnect();
        QMessageBox::information(nullptr, QObject::tr("Database Is Open"),
                    QObject::tr("Connected Successfully !\n"
                                "Click Ok to exit."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Database Is Not Open"),
                    QObject::tr("Connection Failed.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
w.show();
    return a.exec();
}
