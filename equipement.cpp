#include "equipement.h"
#include <QSqlQuery>

equipement::equipement()
{
    id_equipement=""; nom_equipement=" "; type=" "; prix_equipement=0; etat= " ";

}


equipement::equipement(QString id_equipement,QString nom_equipement,QString type,int prix_equipement,QDate date_achat,QString etat)
{
    this->id_equipement=id_equipement;
    this->nom_equipement=nom_equipement;
    this->type=type;
    this->prix_equipement=prix_equipement;
    this->date_achat=date_achat;
    this->etat=etat;
}


QString equipement::getidequipement(){return id_equipement;}
QString equipement::getnomequipement(){return nom_equipement;}
QString equipement::gettype(){return type;}
int equipement::getprixequipement(){return prix_equipement;}
QDate equipement::getdate_achat(){return date_achat;}
QString equipement::getetat(){return etat;}


void equipement::setidequipement(QString id_equipement){this->id_equipement=id_equipement;}
void equipement::setnomequipement(QString nom_equipement){this->nom_equipement=nom_equipement;}
void equipement::settype(QString type){this->type=type;}
void equipement::setprixequipement(int prix_equipement){this->prix_equipement=prix_equipement;}
void equipement::setdate_achat(QDate date_achat){this->date_achat=date_achat;}
void equipement::setetat(QString etat){this->etat=etat;}



/******************************************************************************************************************/

/*******************************************CRUDS*****************************************************/



bool equipement::ajouterequipement()
{

    QSqlQuery query;
    query.prepare("INSERT INTO equipement (id_equipement, nom_equipement, type ,prix_equipement, date_achat,etat) "
                  "VALUES (:id_equipement, :nom_equipement, :type, :prix_equipement, :date_achat, :etat)");// prparation de requette
    query.bindValue(":id_equipement", id_equipement); //remplir CIN2 dans CIN1
    query.bindValue(":nom_equipement", nom_equipement);
    query.bindValue(":type",type);
    query.bindValue(":prix_equipement",prix_equipement);
    query.bindValue(":date_achat",date_achat );
    query.bindValue(":etat",etat);
    return query.exec();

}



/***********************************************************************************************/


QSqlQueryModel* equipement::afficherequipement()
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM equipement ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_equipement"));//nom entite
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_equipement"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_equipement"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_achat"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat"));

     return model;
}


/***********************************************************************************************/


bool equipement::supprimerequipement(QString id_equipement)
{
    QSqlQuery query;
    query.prepare(" Delete from equipement where id_equipement=:id_equipement ");
    query.bindValue(":id_equipement",id_equipement);

    return query.exec();
}



/***********************************************************************************************/



bool equipement::modifierequipement(QString id_equipement, QString nom_equipement, QString type, int prix_equipement, QDate date_achat, QString etat)
{

    QSqlQuery query;
    query.prepare("update equipement set nom_equipement=:nom_equipement,type=:type,prix_equipement=:prix_equipement,date_achat=:date_achat,etat=:etat where id_equipement=:id_equipement");
    query.bindValue(":id_equipement",id_equipement);
    query.bindValue(":nom_equipement",nom_equipement);
    query.bindValue(":type",type);
    query.bindValue(":prix_equipement",prix_equipement);
    query.bindValue(":date_achat",date_achat);
    query.bindValue(":etat",etat);
    return query.exec();

}


/**************************************************************************************************/


QSqlQueryModel * equipement::Rechercheequipement(QString recherche)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM equipement WHERE id_equipement LIKE '"+recherche+"%' OR nom_equipement LIKE '"+recherche+"%' OR type LIKE '"+recherche+"%' OR prix_equipement LIKE '"+recherche+"%' OR date_achat LIKE '"+recherche+"%' OR etat LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_equipement"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_equipement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_equipement"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_achat"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("etat"));


    return model;
}

/*****************************************************************************************************/


QSqlQueryModel * equipement::trierequipementParid()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM equipement order by ID_EQUIPEMENT ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

QSqlQueryModel * equipement::trierequipementParNom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM equipement order by NOM_EQUIPEMENT ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


QSqlQueryModel * equipement::trierequipementParDate()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM equipement order by DATE_ACHAT ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}




