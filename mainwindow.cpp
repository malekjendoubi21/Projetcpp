#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSound>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_equipement_clicked()
{

    QMessageBox::information(nullptr, QObject::tr("Gestion Equipement"),
                                    QObject::tr("Welcom Imed."), QMessageBox::Ok);
     imed.show();
}
