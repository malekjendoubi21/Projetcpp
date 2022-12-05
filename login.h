#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMainWindow>
#include "gestion_equipement.h"
#include "gestion_employe.h"
#include "menu.h"


namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_pushButton_Login_clicked();

private:
    Ui::login *ui;

};



#endif // LOGIN_H
