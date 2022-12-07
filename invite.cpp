#include "invite.h"
#include <QtDebug>
#include <QObject>
#include <QMainWindow>
#include <QMessageBox>
invite::invite()
{

}
invite::invite( QString NOM,QString PRENOM,int NUM_TEL,int CIN ,QString EMAIL,int PRESANCE)
{
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->NUM_TEL=NUM_TEL;
    this->CIN=CIN;
    this->EMAIL=EMAIL;
    this->PRESANCE=PRESANCE;

}
QSqlQueryModel * invite::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from INVITE ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUM_TEL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PRESANCE"));

    return model;

}
QSqlQueryModel* invite ::afficher_cin()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT CIN from INVITE");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    return model;
}
bool invite:: ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(CIN);
    query.prepare("INSERT INTO INVITE(CIN,NUM_TEL,EMAIL,NOM,PRENOM,PRESANCE)" "VALUES (:CIN,:NUM_TEL,:EMAIL,:NOM,:PRENOM,:PRESANCE)");
    query.bindValue(":CIN", CIN);

    query.bindValue(":NUM_TEL", NUM_TEL);
    query.bindValue(":EMAIL", EMAIL);
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":PRESANCE",PRESANCE);

    return query.exec();
}
bool invite:: supprimer(int CIN)
{
    QSqlQuery query;
    query.prepare("DELETE FROM INVITE where CIN=:CIN");
    query.bindValue(":CIN", CIN);
    return   query.exec();


}
bool invite::update()
{
    QSqlQuery query;
            query.prepare("UPDATE INVITE SET NOM=:NOM, PRENOM=:PRENOM,NUM_TEL=:NUM_TEL, EMAIL=:EMAIL, PRESANCE=:PRESANCE WHERE CIN=:CIN ");
            query.bindValue(":CIN", CIN);
            query.bindValue(":NOM", NOM);
            query.bindValue(":PRENOM", PRENOM);
            query.bindValue(":NUM_TEL", NUM_TEL);
            query.bindValue(":EMAIL", EMAIL);
            query.bindValue(":PRESANCE", PRESANCE);
        return query.exec();
}
QSqlQueryModel *invite::tri_CIN()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from INVITE order by CIN");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NUM_TEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EEMAIL"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PRESANCE"));


    return model;

}
QSqlQueryModel *invite::tri_nom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from INVITE order by NOM");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NUM_TEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EEMAIL"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PRESANCE"));
    return model;
}
void invite::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}
void invite::chercheCIN(QTableView *table, int x)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select * from INVITE where regexp_like(CIN,:CIN);");
    query->bindValue(":CIN",x);
    if(x==0)
    {
        query->prepare("select * from INVITE;");
    }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void invite::chercheNom(QTableView *table, QString x)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query =new QSqlQuery;
    query->prepare("select * from INVITE where regexp_like(NOM,:NOM);");
    query->bindValue(":NOM",x);
    if(x==0)
    {
        query->prepare("select * from INVITE;");
    }
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
