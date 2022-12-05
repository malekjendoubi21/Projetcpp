#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Afficher_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_comboBox_activated();


    void on_lineEdit_recherche_textChanged();


    void on_pushButton_clicked();

    void on_pushButton_PDF_clicked();

    void on_pushButton_Login_clicked();

    void on_pushButton_QRcode_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;
};

#endif // MAINWINDOW_H
