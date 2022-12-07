#ifndef DIALOG_INVITE_H
#define DIALOG_INVITE_H
#include "invite.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "arduino.h"
#include <QDialog>

namespace Ui {
class Dialog_invite;
}

class Dialog_invite : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_invite(QWidget *parent = nullptr);
    ~Dialog_invite();
private slots:
    void on_Ajouter_clicked();

    void on_Modifier_clicked();

    void on_Supprimer_clicked();

    void on_TriID_clicked();

    void on_TriNom_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_Recherche_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_EnvoyerSMS_clicked();void postrequest(QString smsmsg,QString phonenumber);

    void update_label();
private:
    Ui::Dialog_invite *ui;
    invite I;
    QByteArray data; //variable contenant les donnees recues
    arduino A;
};

#endif // DIALOG_INVITE_H
