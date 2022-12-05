#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestion_equipement.h"
#include "gestion_employe.h"
#include "login.h"

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
    //void on_pushButton_equipement_clicked();

    //void on_pushButton_employe_clicked();
public:

    Ui::MainWindow *ui;
private:
    gestion_equipement imed;
    gestion_employe aziz;
};
#endif // MAINWINDOW_H
