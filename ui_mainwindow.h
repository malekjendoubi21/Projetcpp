/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *Ajouter;
    QPushButton *Modifier;
    QPushButton *Supprimer;
    QComboBox *comboBox;
    QPushButton *TriNom;
    QPushButton *TriID;
    QLineEdit *LineRecherche;
    QPushButton *Recherche;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QTextEdit *textEdit;
    QPushButton *EnvoyerSMS;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *Linecin;
    QLineEdit *LineNom;
    QLineEdit *LinePrenom;
    QLineEdit *LineNumTel;
    QLineEdit *Linepresence;
    QLineEdit *LineEmail;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 270, 771, 192));
        Ajouter = new QPushButton(centralwidget);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        Ajouter->setGeometry(QRect(290, 80, 75, 23));
        Modifier = new QPushButton(centralwidget);
        Modifier->setObjectName(QStringLiteral("Modifier"));
        Modifier->setGeometry(QRect(290, 110, 75, 23));
        Supprimer = new QPushButton(centralwidget);
        Supprimer->setObjectName(QStringLiteral("Supprimer"));
        Supprimer->setGeometry(QRect(290, 140, 75, 23));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(290, 40, 71, 22));
        TriNom = new QPushButton(centralwidget);
        TriNom->setObjectName(QStringLiteral("TriNom"));
        TriNom->setGeometry(QRect(650, 240, 75, 23));
        TriID = new QPushButton(centralwidget);
        TriID->setObjectName(QStringLiteral("TriID"));
        TriID->setGeometry(QRect(560, 240, 75, 23));
        LineRecherche = new QLineEdit(centralwidget);
        LineRecherche->setObjectName(QStringLiteral("LineRecherche"));
        LineRecherche->setGeometry(QRect(490, 490, 116, 20));
        Recherche = new QPushButton(centralwidget);
        Recherche->setObjectName(QStringLiteral("Recherche"));
        Recherche->setGeometry(QRect(630, 490, 75, 23));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(500, 520, 83, 18));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(500, 540, 83, 18));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(480, 80, 131, 71));
        EnvoyerSMS = new QPushButton(centralwidget);
        EnvoyerSMS->setObjectName(QStringLiteral("EnvoyerSMS"));
        EnvoyerSMS->setGeometry(QRect(510, 160, 75, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(25, 60, 61, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 60, 118, 152));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Linecin = new QLineEdit(layoutWidget1);
        Linecin->setObjectName(QStringLiteral("Linecin"));

        verticalLayout_2->addWidget(Linecin);

        LineNom = new QLineEdit(layoutWidget1);
        LineNom->setObjectName(QStringLiteral("LineNom"));

        verticalLayout_2->addWidget(LineNom);

        LinePrenom = new QLineEdit(layoutWidget1);
        LinePrenom->setObjectName(QStringLiteral("LinePrenom"));

        verticalLayout_2->addWidget(LinePrenom);

        LineNumTel = new QLineEdit(layoutWidget1);
        LineNumTel->setObjectName(QStringLiteral("LineNumTel"));

        verticalLayout_2->addWidget(LineNumTel);

        Linepresence = new QLineEdit(layoutWidget1);
        Linepresence->setObjectName(QStringLiteral("Linepresence"));

        verticalLayout_2->addWidget(Linepresence);

        LineEmail = new QLineEdit(layoutWidget1);
        LineEmail->setObjectName(QStringLiteral("LineEmail"));

        verticalLayout_2->addWidget(LineEmail);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(680, 70, 77, 83));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(layoutWidget2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(layoutWidget2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout_3->addWidget(pushButton_6);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 230, 241, 21));
        label_7->setStyleSheet(QStringLiteral("border: 1px solid black;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        Modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        Supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        TriNom->setText(QApplication::translate("MainWindow", "Tri Nom", Q_NULLPTR));
        TriID->setText(QApplication::translate("MainWindow", "Tri ID", Q_NULLPTR));
        Recherche->setText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        EnvoyerSMS->setText(QApplication::translate("MainWindow", "Envoyer SMS", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Num Tel", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Presence", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Stats", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Mailing", Q_NULLPTR));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
