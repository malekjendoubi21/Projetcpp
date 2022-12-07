#include "dialog_invite.h"
#include "ui_dialog_invite.h"
#include "dialog_mailing.h"
#include "invite.h"
#include "dialog_stats.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPushButton>
#include <QPdfWriter>
#include <QPainter>
#include <QRadioButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QHttpMultiPart>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include <QEventLoop>
Dialog_invite::Dialog_invite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_invite)
{
    ui->setupUi(this);
    ui->Linecin->setValidator( new QIntValidator(0, 99999999, this));
    ui->LineNumTel->setValidator( new QIntValidator(0, 99999999, this));
    ui->comboBox->setModel(I.afficher_cin());
    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is availble and connected to :"<< A.getarduino_port_name();
        break;
    case(1):qDebug()<< "arduino is availble but not connected to :"<< A.getarduino_port_name();
        break;
    case(-1):qDebug()<< "arduino is not availble";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

Dialog_invite::~Dialog_invite()
{
    delete ui;
}
void Dialog_invite::on_Ajouter_clicked()
{
    int CIN=ui->Linecin->text().toInt();
    QString NOM=ui->LineNom->text();
    QString PRENOM=ui->LinePrenom->text();
    int NUM_TEL=ui->LineNumTel->text().toInt();
    int PRESANCE=ui->Linepresence->text().toInt();
    QString EMAIL=ui->LineEmail->text();
    invite I(NOM,PRENOM,NUM_TEL,CIN,EMAIL,PRESANCE);
    bool test=I.ajouter();
    if(test)
    {
        ui->comboBox->setModel(I.afficher_cin());
        ui->tableView->setModel(I.afficher());
    }
}

void Dialog_invite::on_Modifier_clicked()
{
    int CIN=ui->Linecin->text().toInt();
    QString NOM=ui->LineNom->text();
    QString PRENOM=ui->LinePrenom->text();
    int NUM_TEL=ui->LineNumTel->text().toInt();
    int PRESANCE=ui->Linepresence->text().toInt();
    QString EMAIL=ui->LineEmail->text();
    invite I(NOM,PRENOM,NUM_TEL,CIN,EMAIL,PRESANCE);
    bool test=I.update();
    if(test)
    {
        ui->comboBox->setModel(I.afficher_cin());
        ui->tableView->setModel(I.afficher());
    }
}

void Dialog_invite::on_Supprimer_clicked()
{
    invite I;
    I.set_CIN(ui->comboBox->currentText().toInt());
    bool test=I.supprimer(I.get_CIN());
    if(test)
    {
        ui->tableView->setModel(I.afficher());
        ui->comboBox->setModel(I.afficher_cin());
    }
}

void Dialog_invite::on_TriID_clicked()
{
    ui->tableView->setModel(I.tri_CIN());
}

void Dialog_invite::on_TriNom_clicked()
{
    ui->tableView->setModel(I.tri_nom());
}

void Dialog_invite::on_pushButton_4_clicked()
{
    QPdfWriter pdf("C:/Users/Admin/Desktop/soussia/TacheQt/Liste.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 30));
    //painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("D:/Studies/2A/Projet Desktop Application/Taches Projet Qt/GestionDesSponsors/Logo.png"));
    painter.drawText(3000,1500,"LISTE DES INVITES");
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 50));
    painter.drawRect(2700,200,6300,2600);
    painter.drawRect(0,3000,9600,500);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(1000,3300,"CIN");
    painter.drawText(2000,3300,"NOM");
    painter.drawText(3000,3300,"PRENOM");
    painter.drawText(4000,3300,"NUM_TEL");
    painter.drawText(5000,3300,"EMAIL");
    painter.drawText(6000,3300,"PRESANCE");
    QSqlQuery query;
    query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
    time_t tt;
    struct tm* ti;
    time(&tt);
    ti=localtime(&tt);
    asctime(ti);
    painter.drawText(500,300, asctime(ti));
    query.prepare("select * from INVITE");
    query.exec();
    while (query.next())
    {
        painter.drawText(1000,i,query.value(0).toString());
        painter.drawText(2000,i,query.value(1).toString());
        painter.drawText(3000,i,query.value(2).toString());
        painter.drawText(4000,i,query.value(3).toString());
        painter.drawText(5000,i,query.value(4).toString());
        painter.drawText(6000,i,query.value(5).toString());

        i = i +500;
    }
    int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Admin/Desktop/soussia/TacheQt/Liste.pdf"));
        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}

void Dialog_invite::on_pushButton_5_clicked()
{
    Dialog_stats stats;
    stats.setModal(true);
    stats.exec();
}

void Dialog_invite::on_pushButton_6_clicked()
{
    Dialog_mailing mail;
    mail.setModal(true);
    mail.exec();
}

void Dialog_invite::on_Recherche_clicked()
{
    invite I;
    QString text;

    if (ui->radioButton->isChecked()==true)
    {
        I.clearTable(ui->tableView);
        int CIN=ui->LineRecherche->text().toInt();
        I.chercheCIN(ui->tableView,CIN);
    }
    if (ui->radioButton_2->isChecked()==true)
    {
        I.clearTable(ui->tableView);
        QString Nom=ui->LineRecherche->text();
        I.chercheNom(ui->tableView,Nom);
    }
}

void Dialog_invite::on_comboBox_currentIndexChanged(int)
{
    int CIN=ui->comboBox->currentText().toInt();
    QString cin_1=QString::number(CIN);
    QSqlQuery query1,query2,query3,query4;
    query1.prepare("SELECT * FROM INVITE where CIN='"+cin_1+"'");
    if(query1.exec())
    {
        while (query1.next())
        {
            ui->Linecin->setText(query1.value(0).toString());
            ui->LineNom->setText(query1.value(1).toString());
            ui->LinePrenom->setText(query1.value(2).toString());
            ui->LineNumTel->setText(query1.value(3).toString());
            ui->Linepresence->setText(query1.value(4).toString());
            ui->LineEmail->setText(query1.value(5).toString());
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                              QObject::tr("ECHEC DE chargement .\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void Dialog_invite::postrequest(QString smsmsg,QString phonenumber)
{

    // create custom temporary event loop on stack
    QEventLoop eventLoop;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req( QUrl( QString("https://api.orange.com/smsmessaging/v1/outbound/tel%3A%2B322804/requests") ) );

    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");



    req.setRawHeader("Authorization", "Bearer AtaGc2tuR4KD5WAHFnpSAwG1fUAn");
    QJsonObject msg;
    msg["message"] = smsmsg;
    QJsonObject obj;
    obj["address"] = "tel:+216"+phonenumber;
    obj["senderAddress"] = "tel:+322804";
    obj["outboundSMSTextMessage"] = msg;
    QJsonObject body;
    body["outboundSMSMessageRequest"] = obj;
    QJsonDocument doc(body);
    QByteArray data = doc.toJson();
    QNetworkReply *reply = mgr.post(req,data);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError) {
        //success
        qDebug() << "Success" <<reply->readAll();
        delete reply;
    }
    else {
        //failure
        qDebug() << "Failure" <<reply->errorString() << reply->error();
        delete reply;
    }
}
void Dialog_invite::on_EnvoyerSMS_clicked()
{
    QString numtel=ui->LineNumTel->text();
    QString msg=ui->textEdit->toPlainText();
    postrequest(msg,numtel);
}

void Dialog_invite::update_label()
{
    QByteArray data="0";
    data=A.read_from_arduino();
    if (data == "1")
    {
        ui->label_7->setText("Movement detecté");
    }
    if (data == "0")
    {
        ui->label_7->setText("Aucun Movement");
    }
    qDebug() <<  "data: " <<data;
}
