#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetCPP");//inserer le nom de la source de données ODBC
    db.setUserName("wissem");//inserer nom de l'utilisateur
    db.setPassword("wissem");//inserer mot de passe de cet utilisateur
    if (db.open())
        test=true;
    return  test;
}

void connexion::fermerConnexion(){db.close();}

bool connexion::ourirConnexion(){
    if (db.open())
        return true ;
    else
        return false;

}
