#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include "mainwindow/mainwindow.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QDialog
{
    Q_OBJECT

public:
    LoginForm(QWidget *parent = nullptr, MainWindow* mainwindow = nullptr);
    ~LoginForm();

private slots:
    void on_pushButton_login_clicked();

    void logout();

private:
    Ui::LoginForm *ui;
    MainWindow* mainwindow_ref;
};

#endif // LOGINFORM_H
