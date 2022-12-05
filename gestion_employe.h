#ifndef GESTION_EMPLOYE_H
#define GESTION_EMPLOYE_H
#include <QWidget>
#include "employe.h"



        namespace Ui {
        class gestion_employe;
        }

        class gestion_employe : public QWidget
        {
            Q_OBJECT

        public:
            explicit gestion_employe(QWidget *parent = nullptr);
            ~gestion_employe();

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

            void on_pushButton_QRcode_clicked();



        private:
            Ui::gestion_employe *ui;
            Employe E;

        };


#endif // GESTION_EMPLOYE_H
