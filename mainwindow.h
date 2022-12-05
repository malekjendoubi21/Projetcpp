#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equipement.h"
#include"arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonajfficher_clicked();

    void on_pushButtonajouter_clicked();

    void on_pushButtonsupprimer_clicked();
    void update_label();
    void on_pushButtonmodifier_clicked();

    void on_rechercher_EQUIPEMENT_textChanged();

    void on_trier_equipement_activated();

    void on_pushButtonPDF_clicked();

    void on_pushButtonStatestique_clicked();

private:
    Ui::MainWindow *ui;
    equipement E;
    Arduino A;
    QByteArray data;
};
#endif // MAINWINDOW_H
