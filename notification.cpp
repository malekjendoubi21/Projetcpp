#include "notification.h"

#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}

void notification::notification_ajoutequipement()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Equipements ","nouveau Equipements est ajouté ",QSystemTrayIcon::Information,15000);
}

void notification::notification_supprimerequipement(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Equipements ","nouveau Equipement est supprimé",QSystemTrayIcon::Information,15000);
}


void notification::notification_modifierequipement(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Equipements ","nouveau Equipement est modifié",QSystemTrayIcon::Information,15000);

}

















