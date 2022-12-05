#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>


class equipement
{
public:
    equipement();
    equipement(QString,QString,QString,int,QDate,QString);
    QString getidequipement();
    QString getnomequipement();
    QString gettype();
    int getprixequipement();
    QDate getdate_achat();
    QString getetat();



    void setidequipement(QString);
    void setnomequipement(QString);
    void settype(QString);
    void setprixequipement(int);
    void setdate_achat(QDate);
    void setetat(QString);


    bool ajouterequipement();
    QSqlQueryModel* afficherequipement();
    bool supprimerequipement(QString);
    bool modifierequipement(QString,QString,QString,int,QDate,QString);
    QSqlQueryModel* Rechercheequipement(QString);
    QSqlQueryModel * trierequipementParid();
    QSqlQueryModel * trierequipementParNom();
    QSqlQueryModel * trierequipementParDate();


private:
    int prix_equipement;
    QString nom_equipement,type,etat,id_equipement;
    QDate date_achat;
};


#endif // EQUIPEMENT_H
