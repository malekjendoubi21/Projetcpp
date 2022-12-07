#include "gestion_programme.h"
#include "ui_gestion_programme.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QObject>
#include "connexion.h"
#include "emission.h"
#include <QMessageBox>
#include "incendie.h"
#include "exportexcelobjet.h"
#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QUrl>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QFile>
#include <QDataStream>
#include <QIntValidator>
#include <QSqlQuery>
#include <QUrl>
#include <QPdfWriter>
#include <QUrlQuery>
#include <QPrinter>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "statistique.h"
#include "ui_statistique.h"
#include <QIntValidator>
#include <QValidator>
#include <arduino.h>

gestion_programme::gestion_programme(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestion_programme)
{   Emission Em ;
  arduino A;

    ui->setupUi(this);
    ui->tab_emission->setModel(Em.afficher());

    ui->lidemission->setValidator(new QIntValidator(0,99999999,this));
    ui->lnom_emission->setInputMask("aaaaaaaaaaaaaaaaaaa");
    ui->ltemps->setValidator(new QIntValidator(0,999,this));
    ui->lidinvite->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_29->setValidator(new QIntValidator(0,99999999,this));
    //ui->tab_emission->setModel(E.tri());

}

gestion_programme::~gestion_programme()
{
    delete ui;
}
void gestion_programme::on_pB_ajouter_clicked()
{
    int idemission=ui->lidemission->text().toInt();
   QString nom_emission=ui->lnom_emission->text();
     //QString nom_animateur=ui->lnom_animateur->text();
      int temps=ui->ltemps->text().toInt();
      int idinvite=ui->lidinvite->text().toInt();
      int jour=ui->ljour->text().toInt();
      QString message ;
   Emission Em(idemission,nom_emission,temps,idinvite,jour,message);

   bool test=Em.ajouter();

     if(test)
   {
         ui->tab_emission->setModel(Em.afficher());
      //   ui->tab_emission->setModel(E.tri());


       QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("ajout successfully.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);}


       else
          { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("ajout failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);}

}
void gestion_programme::on_detett_clicked()
{   Emission Em;
    int idemission=ui->lineEdit_29->text().toInt();


     //QString nom_animateur=ui->lnom_animateur->text();
  //   bool test=E.detett(idemission)  ;
    QMessageBox msgBox;
    if(Em.rech(idemission))
    {
       if (Em.detett(idemission))
       {
           ui->tab_emission->setModel(Em.afficher());

           QMessageBox::information(nullptr, QObject::tr("database is open"),
                           QObject::tr("Deleted successfully.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);}


           else
              { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                           QObject::tr("Delete failed \n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);}
   }
   else{ QMessageBox::critical(nullptr, QObject::tr("Not found"),
                               QObject::tr("Not found \n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}





}


void gestion_programme::on_modifer_clicked()
{
    int idemission=ui->lidemission->text().toInt();
   QString nom_emission=ui->lnom_emission->text();
     //QString nom_animateur=ui->lnom_animateur->text();
      int temps=ui->ltemps->text().toInt();
      int idinvite=ui->lidinvite->text().toInt();
      int jour=ui->ljour->text().toInt();
     QString message ;
    Emission Em(idemission,nom_emission,temps,idinvite,jour,message);
    QMessageBox msgBox;
    if(Em.rech(idemission))
    {
    if (Em.modifer(idemission,nom_emission,temps,idinvite,jour))
    {          ui->tab_emission->setModel(Em.afficher());
      //  ui->tab_emission->setModel(E.tri());

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("UPDATE successfully.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}


        else
           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("UPDATE failed \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }}

    else{ QMessageBox::critical(nullptr, QObject::tr("Not found"),
                                QObject::tr("Not found \n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

    }
}




void gestion_programme::on_pdf_clicked()
{

    QPdfWriter pdf("D:/2A/projet c++/Emission.pdf");

       QPainter painter(&pdf);
       QString strStream;

         QTextStream out(&strStream);
       int i = 4000;
              painter.setPen(Qt::blue);
              painter.setFont(QFont("Time New Roman", 25));
              painter.drawText(3000,1400,"Liste Des Emissions");
              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              painter.drawRect(100,100,9400,2500);
              painter.drawRect(100,3000,9400,500);
              painter.setFont(QFont("Time New Roman", 9));
              painter.drawText(500,3300,"idemission");
              painter.drawText(2000,3300,"nom_emission");
              painter.drawText(3500,3300,"temps");
              painter.drawText(5000,3300,"idinvite");
              painter.drawText(6500,3300,"jour");

              painter.drawRect(100,3000,9400,9000);
              out <<  "<html>\n"
                      "<img src=\"D:/2A/projet c++/graphique/gestion_de_programme/logo.png\" height=\"120\" width=\"120\"/>"
                      "<html>\n";

              QSqlQuery query;
              query.prepare("select * from Emission");
              query.exec();
              while (query.next())
              {
                  painter.drawText(500,i,query.value(0).toString());
                  painter.drawText(2000,i,query.value(1).toString());
                  painter.drawText(3500,i,query.value(2).toString());
                  painter.drawText(5000,i,query.value(3).toString());
                  painter.drawText(6500,i,query.value(4).toString());
                 i = i + 350;
              }
              QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_programme::on_recherche_clicked()
{
    int idemission=ui->lidemission1->text().toInt();
        QSqlQueryModel *verif=Em.recherche(idemission);
        if(Em.rech(idemission))
        {
        if (verif!=nullptr)
                     {
                         ui->tab_chercher->setModel((verif));
                         QMessageBox::information(this, QObject::tr("recherche successfully!"),
                         QObject::tr("recherche successfully!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
                     else
{
                         QMessageBox::information(this, QObject::tr("recherche failed!"),
                         QObject::tr("recherche failed!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}}
        else{ QMessageBox::critical(nullptr, QObject::tr("Not found"),
                                    QObject::tr("Not found \n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }





void gestion_programme::on_actionplay_clicked()
{
    player= new QMediaPlayer ;
    vw=new QVideoWidget;

    auto filename=QFileDialog::getOpenFileName(this,"import mp4 file",QDir::rootPath(),"Excel Files(*.mp4)");

    vw->setGeometry(100,100,300,400);

    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile(filename));
    //player->setMedia(QUrl::fromLocalFile("/C:/Users/malek jendoubi/Downloads/video final.mp4"));
    vw->show();
    player->play();
}

void gestion_programme::on_actionstop_clicked()
{ player->stop();
    vw->close();

}

void gestion_programme::on_Lid_clicked()
{
     Emission Em;

     QMessageBox msgBox;


          ui->tab_tri->setModel(Em.tri());
    /* QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("tri successfully.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);*/



}

void gestion_programme::on_lduree1_clicked()
{
    Emission Em;

    QMessageBox msgBox;

     ui->tab_tri->setModel(Em.tri2());
     /*  QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("tri successfully.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);*/
}


void gestion_programme::on_ltriidinvite_clicked()
{
    Emission Em;

    QMessageBox msgBox;

     ui->tab_tri->setModel(Em.tri3());
  /*  QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("tri successfully.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

}

void gestion_programme::on_satistique_clicked()
{/*
 statistique W1 ;
 W1.show();

 QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("statistique successfully.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/
    statistique stat ;
    stat.exec();
}

void gestion_programme::on_afficher_clicked()
{
 /*    arduino a ;
     QByteArray data ;
     QSqlQuery query;
Emission E;
QMessageBox msgBox;

     QString message = "successfully" ;
     QString messagee ="failed" ;
  //   data =a.read_from_arduino();
   // if (data)
    //{

           query.prepare("INSERT INTO EMISSION (MESSAGE) "
                      "VALUES (:message)");
       query.bindValue(":message",message);
        ui->tab_chercher->setModel(E.afficher());
  //}
     //else
   //  {

         query.prepare("INSERT INTO EMISSION (MESSAGE) "
                       "VALUES (:messagee)");
        query.bindValue(":message",messagee);
 QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("affichage  failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel)+;*/

   //  }
        incendie inc;
        //inc=new incendie(this);
        inc.exec();
}

void gestion_programme::on_pushButton_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino

}

void gestion_programme::on_pushButton_2_clicked()
{
    A.write_to_arduino("0");  //envoyer 0 à arduino

}

void gestion_programme::on_pushButton_3_clicked()
{
    A.write_to_arduino("2");  //envoyer 0 à arduino

}

void gestion_programme::on_pushButton_4_clicked()
{     A.write_to_arduino("3");  //envoyer 0 à arduino


}



void gestion_programme::on_Excel_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "mydata", ui->tab_tri);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "id_emission", "char(20)");
                obj.addField(1, "nom_emission", "char(20)");
                obj.addField(2, "temps", "char(20)");
                obj.addField(3, "idinvite", "char(20)");
                obj.addField(4, "jour", "char(20)");


                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
                }
}
