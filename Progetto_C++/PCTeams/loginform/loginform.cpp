#include "loginform/loginform.h"
#include "ui_loginform.h"
#include <QPixmap>
#include <iostream>
#include <memory>
#include "user/userrepository.h"

LoginForm::LoginForm(QWidget *parent, MainWindow* mainwindow) :
    QDialog(parent),
    ui(new Ui::LoginForm)
{
    /*
     * Layout setup
     *
    */
    ui->setupUi(this);
    setFixedSize(this->geometry().width(),this->geometry().height()); //set fixed size of the window

    setWindowIcon(QIcon(":img/img/icona.ico"));

    QPixmap pix(":/img/img/LOGO.png");
    ui->label_pic->setPixmap(pix.scaled(ui->label_pic->width(),ui->label_pic->height(), Qt::KeepAspectRatio));

    mainwindow_ref = mainwindow;

    connect(mainwindow,SIGNAL(logout()),this,SLOT(logout()));

}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::logout()
{
    mainwindow_ref->hide();
    ui->lineEdit_password->clear();
    ui->lineEdit_userid->clear();
    ui->label_error->clear();
    this->show();
}

void LoginForm::on_pushButton_login_clicked()
{
    int userid = ui->lineEdit_userid->text().toInt();
    QString password = ui->lineEdit_password->text();

    std::shared_ptr<User> user = UserRepository::getInstance()->getUserById(userid);

    if(user != 0 && user->getPassword().compare(password) == 0){
        mainwindow_ref->show();
        mainwindow_ref->inizializeMainWindowsUi(user);
        this->hide();
    }
    else{
        ui->label_error->setText("Username e/o password errati !!!");
        ui->lineEdit_password->setText("");
        ui->lineEdit_userid->setText("");
    }
}

