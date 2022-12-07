#include "gestion_employe.h"
#include "ui_gestion_employe.h"

#include "employe.h"
#include "qrcode.h"
#include <QMessageBox>
#include <QIntValidator>


#include<QPieSlice >
#include<QPieSeries>
#include <QFileDialog>
#include<QtCharts>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>


gestion_employe::~gestion_employe()
{
    delete ui;
}



   gestion_employe::gestion_employe(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::gestion_employe)
{
    ui->setupUi(this);
}


   void gestion_employe::on_pushButton_Ajouter_clicked()
   {
           int id=ui->lineEdit_id->text().toInt(); //convertir en entier
           QString nom=ui->lineEdit_Nom->text();
           QString prenom=ui->lineEdit_Prenom->text();
           QString sexe=ui->comboBox_Sexe->currentText();
           int num_tel=ui->lineEdit_tel->text().toInt();
           QString email=ui->lineEdit_Email->text();
           QString adress=ui->lineEdit_Adress->text();
           Employe E(id,nom,prenom,sexe,num_tel,email,adress);
               bool test=E.ajouterEmploye();
               if(test)
                     {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                                   QObject::tr("ajout successful.\n"
                                                               "Click Cancel to exit."), QMessageBox::Cancel);
                                    ui->tableView->setModel(E.afficherEmploye());
                     }
                                   else
                                       QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                                   QObject::tr("ajout failed.\n"
                                                               "Click Cancel to exit."), QMessageBox::Cancel);

                    ui->lineEdit_id->clear();
                    ui->lineEdit_Nom->clear();
                    ui->lineEdit_Prenom->clear();
                    ui->comboBox_Sexe->setCurrentIndex(0);
                    ui->lineEdit_tel->clear();
                    ui->lineEdit_Email->clear();
                    ui->lineEdit_Adress->clear();
   }






   void gestion_employe::on_pushButton_Afficher_clicked()
   {
       ui->tableView->setModel(E.afficherEmploye());
   }

   void gestion_employe::on_pushButton_Supprimer_clicked()
   {
       Employe E1;
           E1.setid(ui->lineEdit_id->text().toInt());
           bool test=E1.supprimerEmploye(E1.getid());
           QMessageBox msgBox;
           if (ui->lineEdit_id->text()=="")
           {
               QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                                  QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de CIN"), QMessageBox::Cancel);
           }
           else if (test)
           {
               QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                                  QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
               ui->tableView->setModel(E.afficherEmploye());
           }
           ui->lineEdit_id->clear();
           ui->lineEdit_Nom->clear();
           ui->lineEdit_Prenom->clear();
           ui->comboBox_Sexe->setCurrentIndex(0);
           ui->lineEdit_tel->clear();
           ui->lineEdit_Email->clear();
           ui->lineEdit_Adress->clear();
   }

   void gestion_employe::on_pushButton_modifier_clicked()
   {
           int id=ui->lineEdit_id->text().toInt(); //convertir en entier
           QString nom=ui->lineEdit_Nom->text();
           QString prenom=ui->lineEdit_Prenom->text();
           QString sexe=ui->comboBox_Sexe->currentText();
           int num_tel=ui->lineEdit_tel->text().toInt();
           QString email=ui->lineEdit_Email->text();
           QString adress=ui->lineEdit_Adress->text();
           Employe E(id,nom,prenom,sexe,num_tel,email,adress);


           bool test=E.modifierEmploye(E.getid(),E.getnom(),E.getprenom(),E.getsexe(),E.getnum_tel(),E.getemail(),E.getadress());

           QMessageBox msgBox;

           if (test)
           {
               QMessageBox::information(this, QObject::tr("Modification Succes"),
                                  QObject::tr("Modifications avec Succes"), QMessageBox::Cancel);
               ui->tableView->setModel(E.afficherEmploye());

           }
           else
           {

               QMessageBox::critical(this, QObject::tr("Modification Erreur"),
                                  QObject::tr("Echec de Modification!!!\n""Veuillez remplir tous le champs"), QMessageBox::Cancel);
           }
           ui->lineEdit_id->clear();
           ui->lineEdit_Nom->clear();
           ui->lineEdit_Prenom->clear();
           ui->comboBox_Sexe->setCurrentIndex(0);
           ui->lineEdit_tel->clear();
           ui->lineEdit_Email->clear();
           ui->lineEdit_Adress->clear();
       }



   void gestion_employe::on_tableView_clicked(const QModelIndex &index)
   {
       ui->lineEdit_id->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString());
       ui->lineEdit_Nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString());
       ui->lineEdit_Prenom->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),2)).toString());
       ui->comboBox_Sexe->setCurrentText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),3)).toString());
       ui->lineEdit_tel->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString());
       ui->lineEdit_Email->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),5)).toString());
       ui->lineEdit_Adress->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),6)).toString());


   }

   void gestion_employe::on_comboBox_activated()
   {
               if(ui->comboBox->currentText()=="Tri par Id")
               {
                   ui->tableView->setModel(E.trierEmployeParid());

               }
               else if(ui->comboBox->currentText()=="Tri par Nom")
               {
                   ui->tableView->setModel(E.trierEmployeParNom());

               }
               else
               {
                   ui->tableView->setModel(E.trierEmployeParAdresse());
               }
       }




   void gestion_employe::on_lineEdit_recherche_textChanged()
   {

       QString rech=ui->lineEdit_recherche->text();
       ui->tableView->setModel(E.RechercheEmploye(rech));

   }


   void gestion_employe::on_pushButton_clicked()
   {
       QSqlQueryModel * model= new QSqlQueryModel();
                           model->setQuery("select * from employe where id < 10 ");
                           float id=model->rowCount();
                           model->setQuery("select * from employe where id  between 10 and 100 ");
                           float idd=model->rowCount();
                           model->setQuery("select * from employe where id >100 ");
                           float iddd=model->rowCount();
                           float total=id+idd+iddd;
                           QString a=QString("moins de 10 "+QString::number((id*100)/total,'f',2)+"%" );
                           QString b=QString("entre 10 et 100 "+QString::number((idd*100)/total,'f',2)+"%" );
                           QString c=QString("+10 Ans"+QString::number((iddd*100)/total,'f',2)+"%" );
                           QPieSeries *series = new QPieSeries();
                           series->append(a,id);
                           series->append(b,idd);
                           series->append(c,iddd);
                   if (id!=0)
                   {QPieSlice *slice = series->slices().at(0);
                    slice->setLabelVisible();
                    slice->setPen(QPen());}
                   if ( idd!=0)
                   {
                            // Add label, explode and define brush for 2nd slice
                            QPieSlice *slice1 = series->slices().at(1);
                            //slice1->setExploded();
                            slice1->setLabelVisible();
                   }
                   if(iddd!=0)
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
                           chart->setTitle("Pourcentage Par Id :Nombre Des Employes "+ QString::number(total));
                           chart->legend()->hide();
                           // Used to display the chart
                           QChartView *chartView = new QChartView(chart);
                           chartView->setRenderHint(QPainter::Antialiasing);
                           chartView->resize(1000,500);
                           chartView->show();

   }



   void gestion_employe::on_pushButton_PDF_clicked()
   {
       QPdfWriter pdf("C:\\Users\\Aziz Mabrouki\\Desktop\\Atelier_Connexion  (1)\\Atelier_Connexion\\PDF_Employe.pdf");

         QPainter painter(&pdf);
         int i = 4000;
                painter.setPen(Qt::red);
                painter.setFont(QFont("Time New Roman", 25));
                painter.drawText(3000,1400,"Liste Des Employes");
                painter.setPen(Qt::black);
                painter.setFont(QFont("Time New Roman", 15));
                painter.drawRect(100,3000,9400,500);
                painter.setFont(QFont("Time New Roman", 9));
                painter.drawText(400,3300,"id");
                painter.drawText(1350,3300,"Nom");
                painter.drawText(2200,3300,"Prenom");
                painter.drawText(3400,3300,"Sexe");
                painter.drawText(4400,3300,"Numero de Tel");
                painter.drawText(6200,3300,"Email");
                painter.drawText(7600,3300,"Adress");
                painter.drawRect(100,3000,9400,9000);

                QSqlQuery query;
                query.prepare("select * from EMPLOYE");
                query.exec();
                while (query.next())
                {
                    painter.drawText(400,i,query.value(0).toString());
                    painter.drawText(1350,i,query.value(1).toString());
                    painter.drawText(2300,i,query.value(2).toString());
                    painter.drawText(3400,i,query.value(3).toString());
                    painter.drawText(4400,i,query.value(4).toString());
                    painter.drawText(6200,i,query.value(5).toString());
                    painter.drawText(7600,i,query.value(6).toString());


                   i = i + 350;
                }
                QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
   }



   void gestion_employe::on_pushButton_QRcode_clicked()
   {

       QString text ="Employe details :"+ ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString()
                               +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),1)).toString()
                               +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),2)).toString()
                               +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),3)).toString()
                               +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString()
                               +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),5)).toString()
                               +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),6)).toString();
                       //text="user data";
                       using namespace qrcodegen;
                         // Create the QR Code object
                         QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );
                         qint32 sz = qr.getSize();
                         QImage im(sz,sz, QImage::Format_RGB32);
                           QRgb black = qRgb(  0,  0,  0);
                           QRgb white = qRgb(255,255,255);
                         for (int y = 0; y < sz; y++)
                           for (int x = 0; x < sz; x++)
                             im.setPixel(x,y,qr.getModule(x, y) ? black : white );
                         ui->qr_code->setPixmap( QPixmap::fromImage(im.scaled(256,256,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );
   }
