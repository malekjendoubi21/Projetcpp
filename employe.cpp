#include "employe.h"
#include <QSqlQuery>


Employe::Employe()
{
id=0; nom=" "; prenom=" "; sexe=" "; num_tel=0; email=" "; adress= " ";
}


Employe::Employe(int id,QString nom,QString prenom,QString sexe,int num_tel,QString email, QString adress)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->num_tel=num_tel;
    this->email=email;
    this->adress=adress;
}



int Employe::getid(){return id;}
QString Employe::getnom(){return nom;}
QString Employe::getprenom(){return prenom;}
QString Employe::getsexe(){return sexe;}
int Employe::getnum_tel(){return num_tel;}
QString Employe::getemail(){return email;}
QString Employe::getadress(){return adress;}


void Employe::setid(int id){this->id=id;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe::setprenom(QString prenom){this->prenom=prenom;}
void Employe::setsexe(QString sexe){this->sexe=sexe;}
void Employe::setnum_tel(int num_tel){this->num_tel=num_tel;}
void Employe::setemail(QString email){this->email=email;}
void Employe::setadress(QString adress){this->adress=adress;}



bool Employe::ajouterEmploye()
{

     QSqlQuery query;
     query.prepare("INSERT INTO EMPLOYE (ID, NOM, PRENOM ,SEXE, NUM_TEL, EMAIL, ADRESS) "
                   "VALUES (:id, :nom, :prenom, :sexe, :num_tel, :email, :adress)");// prparation de requette
     query.bindValue(":id", id);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":sexe",sexe);
     query.bindValue(":num_tel",num_tel);
     query.bindValue(":email",email);
     query.bindValue(":adress",adress);
     return query.exec();

}



QSqlQueryModel* Employe::afficherEmploye()
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM EMPLOYE ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));//nom entite
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_tel"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("email"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("adress"));

     return model;
}



bool Employe::supprimerEmploye(int id)
{
    QSqlQuery query;
    query.prepare(" Delete from EMPLOYE where id=:id ");
    query.bindValue(":id",id);

    return query.exec();
}





bool Employe::modifierEmploye(int id,QString nom,QString prenom,QString sexe,int num_tel,QString email,QString adress)
{

    QSqlQuery query;
    query.prepare("update EMPLOYE set nom=:nom,prenom=:prenom,sexe=:sexe,num_tel=:num_tel,email=:email,adress=:adress where id=:id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",sexe);
    query.bindValue(":num_tel",num_tel);
    query.bindValue(":email",email);
    query.bindValue(":adress",adress);
    return query.exec();

}






QSqlQueryModel* Employe::RechercheEmploye(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM employe WHERE id LIKE '"+recherche+"%' OR nom LIKE '"+recherche+"%' OR prenom LIKE '"+recherche+"%' OR sexe LIKE '"+recherche+"%' OR num_tel LIKE '"+recherche+"%' OR email LIKE '"+recherche+"%' OR adress LIKE '"+recherche+"%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_tel"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("adress"));

return model;
}


/***********************************************************************************************/


QSqlQueryModel * Employe::trierEmployeParid()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM employe order by id ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}



QSqlQueryModel * Employe::trierEmployeParNom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM employe order by nom ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}



QSqlQueryModel * Employe::trierEmployeParAdresse()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM employe order by adress ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

