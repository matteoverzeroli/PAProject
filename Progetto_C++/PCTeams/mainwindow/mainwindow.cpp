#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user/administrator.h"
#include "user/userrepository.h"
#include "user/volunteer.h"
#include "user/foreman.h"
#include "team/team.h"
#include <QDate>
#include <QString>

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

    if(ui->radioButton_nu_admin->isChecked()){
        Administrator* new_admin = new Administrator(ui->lineEdit_nu_psw->text(),
                                                     ui->lineEdit_nu_name->text(),
                                                     ui->lineEdit_nu_surname->text(),
                                                     new QDate(ui->dateEdit_nu_birthday->date()),
                                                     ui->lineEdit_nu_email->text(),
                                                     ui->lineEdit_nu_cellnumber->text(),
                                                     sex);
        admin->addNewUser(new_admin);
        ui->statusbar->setStyleSheet("color:green");
        ui->statusbar->showMessage("Amministratore " + new_admin->toString() + " aggiunto correttamente!");
    }
    else if(ui->radioButton_nu_volunteer->isChecked()){
        Volunteer* new_volunteer = new Volunteer(ui->lineEdit_nu_psw->text(),
                                                 ui->lineEdit_nu_name->text(),
                                                 ui->lineEdit_nu_surname->text(),
                                                 new QDate(ui->dateEdit_nu_birthday->date()),
                                                 ui->lineEdit_nu_email->text(),
                                                 ui->lineEdit_nu_cellnumber->text(),
                                                 sex);
        admin->addNewUser(new_volunteer, ui->comboBox_nu_team->currentText()
                          .split(" ",Qt::SkipEmptyParts)[0].toInt());

        ui->statusbar->setStyleSheet("color:green");
        ui->statusbar->showMessage("Caposquadra " + new_volunteer->toString() + " aggiunto correttamente!");
    }
    else{
        Foreman* new_foreman = new Foreman(ui->lineEdit_nu_psw->text(),
                                                 ui->lineEdit_nu_name->text(),
                                                 ui->lineEdit_nu_surname->text(),
                                                 new QDate(ui->dateEdit_nu_birthday->date()),
                                                 ui->lineEdit_nu_email->text(),
                                                 ui->lineEdit_nu_cellnumber->text(),
                                                 sex);
        admin->addNewUser(new_foreman, ui->comboBox_nu_team->currentText()
                          .split(" ",Qt::SkipEmptyParts)[0].toInt());

        ui->statusbar->setStyleSheet("color:green");
        ui->statusbar->showMessage("Caposquadra " + new_foreman->toString() + " aggiunto correttamente!");
    }
}


void MainWindow::on_radioButton_nu_volunteer_toggled(bool checked)
{
    if(checked){
        ui->comboBox_nu_team->clear();

        std::shared_ptr<Administrator> admin =
                       std::dynamic_pointer_cast<Administrator> (currentuser);

        admin->populateComboBoxTeams(ui->comboBox_nu_team, false);

        ui->comboBox_nu_team->show();
        ui->label_nu_team->show();

    }
    else{
        ui->comboBox_nu_team->hide();
        ui->label_nu_team->hide();
    }
}


void MainWindow::on_radioButton_nu_foreman_toggled(bool checked)
{
    if(checked){
        ui->comboBox_nu_team->clear();

        std::shared_ptr<Administrator> admin =
                       std::dynamic_pointer_cast<Administrator> (currentuser);

        admin->populateComboBoxTeams(ui->comboBox_nu_team, true);

        ui->comboBox_nu_team->show();
        ui->label_nu_team->show();

    }
    else{
        ui->comboBox_nu_team->hide();
        ui->label_nu_team->hide();
    }
}

void MainWindow::on_actionLogout_triggered()
{
    currentuser = std::shared_ptr<User>(nullptr);
    emit logout();
}


void MainWindow::on_pushButton_showuser_clicked()
{

}

