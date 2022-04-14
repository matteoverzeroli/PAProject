#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginform/loginform.h"
#include "user/administrator.h"
#include "user/userrepository.h"
#include "team/teamrepository.h"
#include "team/team.h"
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_team->hide();
    ui->formWidget_team->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inizializeMainWindowsUi(std::shared_ptr<User> user)
{
    user->initializeMainWindow(ui);
    currentuser = user;
}

void MainWindow::on_pushButton_newuser_clicked()
{
    ui->stackedWidget_info->setCurrentIndex(1);
    ui->comboBox_nu_team->hide();
    ui->label_nu_team->hide();
}


void MainWindow::on_pushButton_nu_adduser_clicked()
{

    std::shared_ptr<Administrator> admin =
                   std::dynamic_pointer_cast<Administrator> (currentuser);


    char sex = ui->radioButton_nu_F->isChecked() ? 'F' : 'M';

    if(ui->radioButton_nu_admin->isEnabled()){
        admin->addNewUser(new Administrator(ui->lineEdit_nu_psw->text(),
                                            ui->lineEdit_nu_name->text(),
                                            ui->lineEdit_nu_surname->text(),
                                            new QDate(ui->dateEdit_nu_birthday->date()),
                                            ui->lineEdit_nu_email->text(),
                                            ui->lineEdit_nu_cellnumber->text(),
                                            sex));
    }
}


void MainWindow::on_radioButton_nu_volunteer_toggled(bool checked)
{
    if(checked){
         ui->comboBox_nu_team->show();
         ui->label_nu_team->show();
         auto teams = TeamRepository::getInstance()->getAllTeam();
         for(auto it = teams.begin(); it != teams.end(); ++it){
             ui->comboBox_nu_team->addItem((*it)->getName());
         }
    }
    else{
         ui->comboBox_nu_team->hide();
         ui->label_nu_team->hide();
    }
}

