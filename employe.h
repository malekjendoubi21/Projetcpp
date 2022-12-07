#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
//CRUDS
class Employe

{
public:
    Employe();
    Employe(int,QString,QString,QString,int,QString,QString);

    // getters
    int getid();
    QString getnom();
    QString getprenom();
    QString getsexe();
    int getnum_tel();
    QString getemail();
    QString getadress();


    //setters
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setsexe(QString);
    void setnum_tel(int);
    void setemail(QString);
    void setadress(QString);


    //declaration fonctions
    bool ajouterEmploye();
    QSqlQueryModel* afficherEmploye();
    bool supprimerEmploye(int);
    bool modifierEmploye(int,QString,QString,QString,int,QString,QString);
    QSqlQueryModel* RechercheEmploye(QString);
    QSqlQueryModel * trierEmployeParid();
    QSqlQueryModel * trierEmployeParNom();
    QSqlQueryModel * trierEmployeParAdresse();

    //declaration attribut
private:
    int id,num_tel;
    QString nom,prenom,sexe,email,adress;
};

#endif // EMPLOYES_H
