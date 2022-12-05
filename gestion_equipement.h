#ifndef GESTION_EQUIPEMENT_H
#define GESTION_EQUIPEMENT_H
#include <QWidget>
#include "equipement.h"


namespace Ui {
class gestion_equipement;
}

class gestion_equipement : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_equipement(QWidget *parent = nullptr);
    ~gestion_equipement();

private slots:

    void on_pushButtonajfficher_clicked();

    void on_pushButtonajouter_clicked();

    void on_pushButtonsupprimer_clicked();
    //void update_label();
    void on_pushButtonmodifier_clicked();

    void on_rechercher_EQUIPEMENT_textChanged();

    void on_trier_equipement_activated();

    void on_pushButtonPDF_clicked();

    void on_pushButtonStatestique_clicked();


private:
    Ui::gestion_equipement *ui;
    QByteArray data; // variable contenant les données reçues

};

#endif // GESTION_EQUIPEMENT_H
