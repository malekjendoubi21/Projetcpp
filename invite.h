#ifndef INVITE_H
#define INVITE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>
#include <QTableView>
#include <QFile>

class invite
{
    QString NOM,PRENOM,EMAIL;
    int CIN;
    int NUM_TEL;
    int PRESANCE;
public:
    invite();
    invite(QString ,QString ,int,int,QString,int);
    //get
    QString get_nom(){return NOM;}
    QString get_prenom(){return PRENOM;}
    QString get_email(){return EMAIL;}
    int get_CIN(){return CIN;}
    int get_numtel(){return NUM_TEL ;}
    int get_presance(){return PRESANCE ;}
    //set
    void set_nom(QString n){NOM=n;}
    void set_prenom(QString p){PRENOM=p;}
    void set_email(QString email){EMAIL=email;}
    void set_CIN(int cin){CIN=cin;}
    void set_numtel(int num_tel){NUM_TEL=num_tel;}
    void set_presance(int presance){PRESANCE=presance;}
    //fonctions
    bool ajouter();
    bool supprimer(int);
    bool update();
    //affichage
    QSqlQueryModel * afficher();
    QSqlQueryModel* afficher_cin();
    //trier
    QSqlQueryModel* tri_CIN();
    QSqlQueryModel* tri_nom();
    void clearTable(QTableView * table);
    void chercheCIN(QTableView *table, int x);
    void chercheNom(QTableView *table, QString x);

};

#endif // INVITE_H
