#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include<QtCharts>
#include "notification.h"
notification N;
equipement E;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino

    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

}
void MainWindow::update_label()
{
 data="";

while((A.getdata().size()<5))
{
data=A.read_from_arduino();

break;

}
qDebug()<<data;
if(data!="")
{
    if(A.chercherid(data)!=-1)
    {QString nom=A.chercher(data);
        qDebug() << nom ;
        QByteArray x=nom.toUtf8();
        qDebug() << x ;
        A.write_to_arduino(x);
        qDebug()<<"valdie";

         }
    else
    { A.write_to_arduino("0"); qDebug()<<"invaldie"; }


}
data="";
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonajfficher_clicked()
{
    ui->tableView_equipement->setModel(E.afficherequipement());
}

void MainWindow::on_pushButtonajouter_clicked()
{
    QString id_equipement=ui->lineEdit_id->text() ;
    QString nom_equipement=ui->lineEdit_nom->text();
    QString type=ui->lineEdit_type->text();
    int prix_equipement=ui->lineEdit_prix->text().toInt();
    QDate date_achat=ui->dateEdit_date->date();
    QString etat=ui->lineEdit_etat->text();
    equipement E(id_equipement,nom_equipement,type,prix_equipement,date_achat,etat);
        bool test=E.ajouterequipement();
        if(test)
              {
                    N.notification_ajoutequipement();
                    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                            QObject::tr("ajout successful.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
                             ui->tableView_equipement->setModel(E.afficherequipement());
                             QString nomFile ="Historique";
                                         QFile file("C:\\Users\\imedk\\OneDrive\\Bureau\\Gestionequipement\\Gestionequipement\\Gestionequipement\\"+nomFile+".txt");
                                         QString finalmsg="fichier modifie avec succes";
                                          if(!file.exists()){
                                          finalmsg="fichier cree avec succes";
                                          }
                                         file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                                         QTextStream txt(&file);
                                           QString d_info = QDateTime::currentDateTime().toString();

                                         QString message2=d_info+" - Un Equipement a été ajoutée avec le nom "+ nom_equipement +"\n";
                                         txt << message2;
              }
                            else
                                QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                            QObject::tr("ajout failed.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);

             ui->lineEdit_id->clear();
             ui->lineEdit_nom->clear();
             ui->lineEdit_type->clear();
             ui->lineEdit_prix->clear();
             ui->dateEdit_date->clear();
             ui->lineEdit_etat->clear();
}

void MainWindow::on_pushButtonsupprimer_clicked()
{
    equipement E1;
    E1.setidequipement(ui->lineEdit_id->text());
    bool test=E1.supprimerequipement(E1.getidequipement());
    QMessageBox msgBox;
    if (ui->lineEdit_id->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                           QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de CIN"), QMessageBox::Cancel);
    }
    else if (test)
    {
        N.notification_supprimerequipement();
        QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                           QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
        ui->tableView_equipement->setModel(E.afficherequipement());QString nomFile ="Historique";
        QFile file("C:\\Users\\imedk\\OneDrive\\Bureau\\Gestionequipement\\Gestionequipement\\Gestionequipement\\"+nomFile+".txt");
        QString finalmsg="fichier modifie avec succes";
         if(!file.exists()){
         finalmsg="fichier cree avec succes";
         }
        file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



        QTextStream txt(&file);
          QString d_info = QDateTime::currentDateTime().toString();

        QString message2=d_info+" - Un Equipement a été suprimmé\n";
        txt << message2;
    }


    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_prix->clear();
    ui->dateEdit_date->clear();
    ui->lineEdit_etat->clear();
}

void MainWindow::on_pushButtonmodifier_clicked()
{

    QString id_equipement=ui->lineEdit_id->text() ;
    QString nom_equipement=ui->lineEdit_nom->text();
    QString type=ui->lineEdit_type->text();
    int prix_equipement=ui->lineEdit_prix->text().toInt();
    QDate date_achat=ui->dateEdit_date->date();
    QString etat=ui->lineEdit_etat->text();
    equipement E(id_equipement,nom_equipement,type,prix_equipement,date_achat,etat);

        bool test=E.modifierequipement(E.getidequipement(),E.getnomequipement(),E.gettype(),E.getprixequipement(),E.getdate_achat(),E.getetat());

        QMessageBox msgBox;

        if (test)
        {
            N.notification_modifierequipement();
            QMessageBox::information(this, QObject::tr("Modification Succes"),
                               QObject::tr("Modifications avec Succes"), QMessageBox::Cancel);
            ui->tableView_equipement->setModel(E.afficherequipement());
            QString nomFile ="Historique";
                 QFile file("C:\\Users\\imedk\\OneDrive\\Bureau\\Gestionequipement\\Gestionequipement\\Gestionequipement\\"+nomFile+".txt");
                 QString finalmsg="fichier modifie avec succes";
                  if(!file.exists()){
                  finalmsg="fichier cree avec succes";
                  }
                 file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                 QTextStream txt(&file);
                   QString d_info = QDateTime::currentDateTime().toString();

                 QString message2=d_info+" - Un Equipement a été modifie avec le nom "+ nom_equipement +"\n";
                 txt << message2;

        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Modification Errer"),
                               QObject::tr("Echec de Modification!!!\n""Veuillez remplir tous le champs"), QMessageBox::Cancel);
        }


        ui->lineEdit_id->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_type->clear();
        ui->lineEdit_prix->clear();
        ui->dateEdit_date->clear();
        ui->lineEdit_etat->clear();
}

void MainWindow::on_rechercher_EQUIPEMENT_textChanged()
{

    QString rech=ui->rechercher_EQUIPEMENT->text();
    ui->tableView_equipement->setModel(E.Rechercheequipement(rech));
}


void MainWindow::on_trier_equipement_activated()
{
    if (ui->trier_equipement->currentText()=="Tri Par ID")
    {
        ui->tableView_equipement->setModel(E.trierequipementParid());
    }
    else if(ui->trier_equipement->currentText()=="Tri Par nom")
    {
        ui->tableView_equipement->setModel(E.trierequipementParNom());
    }
    else
    {
        ui->tableView_equipement->setModel(E.trierequipementParDate());
    }
}

void MainWindow::on_pushButtonPDF_clicked()
{
    QPdfWriter pdf("C:\\Users\\imedk\\OneDrive\\Bureau\\Gestionequipement\\Gestionequipement\\Gestionequipement\\PDF_Equipment.pdf");

      QPainter painter(&pdf);
      int i = 4000;
             painter.setPen(Qt::red);
             painter.setFont(QFont("Time New Roman", 25));
             painter.drawText(3000,1400,"Liste Des Equipement");
             painter.setPen(Qt::black);
             painter.setFont(QFont("Time New Roman", 15));
             painter.drawRect(100,3000,9400,500);
             painter.setFont(QFont("Time New Roman", 9));
             painter.drawText(400,3300,"id_equipement");
             painter.drawText(1850,3300,"nom_equipement");
             painter.drawText(3200,3300,"type");
             painter.drawText(3800,3300,"prix_equipement");
             painter.drawText(5600,3300,"date_achat");
             painter.drawText(7300,3300,"etat");
             painter.drawRect(100,3000,9400,9000);

             QSqlQuery query;
             query.prepare("select * from EQUIPEMENT");
             query.exec();
             while (query.next())
             {
                 painter.drawText(500,i,query.value(0).toString());
                 painter.drawText(2000,i,query.value(1).toString());
                 painter.drawText(3300,i,query.value(2).toString());
                 painter.drawText(4000,i,query.value(3).toString());
                 painter.drawText(5400,i,query.value(4).toString());
                 painter.drawText(7400,i,query.value(5).toString());


                i = i + 350;
             }
             QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
             QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButtonStatestique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                         model->setQuery("select * from equipement where prix_equipement < 100 ");
                         float prix=model->rowCount();
                         model->setQuery("select * from equipement where prix_equipement  between 100 and 500 ");
                         float prixx=model->rowCount();
                         model->setQuery("select * from equipement where prix_equipement > 500 ");
                         float prixxx=model->rowCount();
                         float total=prix+prixx+prixxx;
                         QString a=QString("moins de 100 DT  "+QString::number((prix*100)/total,'f',2)+"%" );
                         QString b=QString("entre 100 et 5000 DT  "+QString::number((prixx*100)/total,'f',2)+"%" );
                         QString c=QString("+500 DT  "+QString::number((prixxx*100)/total,'f',2)+"%" );
                         QPieSeries *series = new QPieSeries();
                         series->append(a,prix);
                         series->append(b,prixx);
                         series->append(c,prixxx);
                 if (prix!=0)
                 {QPieSlice *slice = series->slices().at(0);
                  slice->setLabelVisible();
                  slice->setPen(QPen());}
                 if ( prixx!=0)
                 {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabelVisible();
                 }
                 if(prixxx!=0)
                 {
                          // Add labels to rest of slices
                          QPieSlice *slice2 = series->slices().at(2);
                          //slice1->setExploded();
                          slice2->setLabelVisible();
                 }
                         // Create the chart widget
                         QChart *chart = new QChart();
                         // Add data to chart with title and hide legend
                         chart->addSeries(series);
                         chart->setTitle("Pourcentage Par Prix :Nombre Des Equipements "+ QString::number(total));
                         chart->legend()->hide();
                         // Used to display the chart
                         QChartView *chartView = new QChartView(chart);
                         chartView->setRenderHint(QPainter::Antialiasing);
                         chartView->resize(1000,500);
                         chartView->show();

}
