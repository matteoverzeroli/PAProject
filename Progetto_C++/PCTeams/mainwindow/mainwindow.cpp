#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user/administrator.h"
#include "user/userrepository.h"
#include "user/volunteer.h"
#include "user/foreman.h"
#include "team/team.h"
#include <QDate>
#include <QString>
#include <QMessageBox>

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
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_info->setCurrentIndex(0);

    ui->commandLinkButton_deleteuser->hide();
    ui->commandLinkButton_newuser->hide();
    ui->commandLinkButton_showusers->hide();
    ui->pushButton_op_newop->hide();

    user->initializeMainWindow(ui);
    currentuser = user;
}

void MainWindow::on_pushButton_nu_adduser_clicked()
{
    if(!nullNewUserAttribute()){

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
                                                         sex, new QPixmap(ui->lineEdit_pathpic->text()));
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
                                                     sex, new QPixmap(ui->lineEdit_pathpic->text()));
            admin->addNewUser(new_volunteer, ui->comboBox_nu_team->currentText()
                              .split(" ",Qt::SkipEmptyParts)[0].toInt());

            ui->statusbar->setStyleSheet("color:green");
            ui->statusbar->showMessage("Volontario " + new_volunteer->toString() + " aggiunto correttamente!");
        }
        else{
            Foreman* new_foreman = new Foreman(ui->lineEdit_nu_psw->text(),
                                                     ui->lineEdit_nu_name->text(),
                                                     ui->lineEdit_nu_surname->text(),
                                                     new QDate(ui->dateEdit_nu_birthday->date()),
                                                     ui->lineEdit_nu_email->text(),
                                                     ui->lineEdit_nu_cellnumber->text(),
                                                     sex, new QPixmap(ui->lineEdit_pathpic->text()));

            admin->addNewUser(new_foreman, ui->comboBox_nu_team->currentText()
                              .split(" ",Qt::SkipEmptyParts)[0].toInt());

            ui->statusbar->setStyleSheet("color:green");
            ui->statusbar->showMessage("Caposquadra " + new_foreman->toString() + " aggiunto correttamente!");

            clearNewUserAttribute();
        }
    }
    else{
        QMessageBox::critical(this, "Errore", "Alcuni campi vuoti!", QMessageBox::Ok);
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

void MainWindow::on_comboBox_du_team_currentTextChanged(const QString &text)
{
    ui->listWidget_user->clear();

    std::shared_ptr<Administrator> admin =
                   std::dynamic_pointer_cast<Administrator> (currentuser);

    if(text.compare("Amministratori") != 0 && !text.isEmpty()){
        int idselectedteam = text.split(" ",Qt::SkipEmptyParts)[0].toInt();

        admin->populateListBoxUsers(ui->listWidget_user, idselectedteam);
    }
    else if(text.compare("Amministratori") == 0){
        admin->populateListBoxUsers(ui->listWidget_user);
    }
}


void MainWindow::on_pushButton_du_deleteuser_clicked()
{
    std::shared_ptr<Administrator> admin =
                   std::dynamic_pointer_cast<Administrator> (currentuser);
    QString text = ui->listWidget_user->currentItem()->text();
    if(!text.isEmpty()){
        int iduser = text.split(" ",Qt::SkipEmptyParts)[0].toInt();
        if(iduser != currentuser->getIduser()){

           QMessageBox::StandardButton reply = QMessageBox::question(this, "Cancella utente", "Sei sicuro di volere cancellare l'utente con id "
                                 + QString::number(iduser) + "?", QMessageBox::Yes | QMessageBox::No);

           if(reply == QMessageBox::Yes){
               admin->deleteUser(iduser);
               ui->statusbar->setStyleSheet("color:red");
               ui->statusbar->showMessage("Utente " + QString::number(iduser) + " cancellato!" );
               on_commandLinkButton_deleteuser_clicked();
           }
        }
        else{
            QMessageBox::critical(this, "Errore", "Non puoi cancellare te stesso!", QMessageBox::Ok);
        }
    }
}

void MainWindow::on_pushButton_op_add_clicked()
{
    if(!nullNewOperationAttribute()){

        std::shared_ptr<Foreman> foreman =
                       std::dynamic_pointer_cast<Foreman> (currentuser);

        Operation* new_op = new Operation(ui->lineEdit_op_name->text(),ui->lineEdit_op_address->text(),
                                        new QGeoCoordinate(ui->lineEdit_op_lat->text().toDouble(),ui->lineEdit_op_lng->text().toDouble()),
                                        ui->lineEdit_op_petitioner->text(), ui->lineEdit_op_cellnumber->text(),
                                        Operation::stringToColor(ui->comboBox_op_color->currentText()),
                                        UserRepository::getInstance()->getUserById((ui->comboBox_op_users->currentText().split(" ",Qt::SkipEmptyParts))[0].toInt()),
                                        foreman->getTeam(),new QDateTime(ui->dateTimeEdit_op_start->dateTime()),
                                        new QDateTime(ui->dateTimeEdit_op_stop->dateTime()));
        foreman->addNewOperation(new_op);

        clearNewOperationAttribute();
        ui->stackedWidget_info->setCurrentIndex(3);

        ui->statusbar->setStyleSheet("color:green");
        ui->statusbar->showMessage("Intervento: " + new_op->toString() + " aggiunto correttamente!");
    }
    else{
        QMessageBox::critical(this, "Errore", "Alcuni campi vuoti!", QMessageBox::Ok);
    }
}


void MainWindow::on_pushButton_op_newop_clicked()
{   
    ui->stackedWidget_info->setCurrentIndex(4);

    ui->comboBox_op_color->addItem(Operation::colorToString(COLOR::RED));
    ui->comboBox_op_color->addItem(Operation::colorToString(COLOR::ORANGE));
    ui->comboBox_op_color->addItem(Operation::colorToString(COLOR::GREEN));

    std::shared_ptr<Foreman> foreman =
                   std::dynamic_pointer_cast<Foreman> (currentuser);

    foreman->populateComboBoxTeams(ui->comboBox_op_teams, false);
    foreman->populateVolunteerComboBox(ui->comboBox_op_users);
}


void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    ui->listWidget_op->show();

    std::shared_ptr<Volunteer> volunteer =
                   std::dynamic_pointer_cast<Volunteer> (currentuser);
    volunteer->populateOperationList(ui->listWidget_op, date);

    ui->dateTimeEdit_op_start->setDate(ui->calendarWidget->selectedDate());
    ui->dateTimeEdit_op_stop->setDate(ui->calendarWidget->selectedDate());
}
void MainWindow::on_commandLinkButton_newuser_clicked()
{
    ui->stackedWidget_info->setCurrentIndex(1);
    ui->comboBox_nu_team->hide();
    ui->label_nu_team->hide();
}


void MainWindow::on_commandLinkButton_operation_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_info->setCurrentIndex(3);
    ui->listWidget_op->hide();
}


void MainWindow::on_commandLinkButton_deleteuser_clicked()
{
    ui->pushButton_du_deleteuser->show();
    ui->comboBox_du_team->clear();

    ui->stackedWidget_info->setCurrentIndex(2);

    std::shared_ptr<Administrator> admin =
                   std::dynamic_pointer_cast<Administrator> (currentuser);

    admin->populateComboBoxTeams(ui->comboBox_du_team, false);
}

void MainWindow::on_commandLinkButton_showusers_clicked()
{
    ui->comboBox_du_team->clear();
    ui->listWidget_user->clear();
    ui->pushButton_du_deleteuser->hide();
    ui->stackedWidget_info->setCurrentIndex(2);

    std::shared_ptr<Administrator> admin =
                   std::dynamic_pointer_cast<Administrator> (currentuser);

    ui->comboBox_du_team->addItem("Amministratori");
    admin->populateComboBoxTeams(ui->comboBox_du_team, false);

    ui->listWidget_user->clear();
    admin->populateListBoxUsers(ui->listWidget_user);
}

/**
 * Verifica che i campi del nuovo utente da inserire non siano vuoti
 *
 * @brief MainWindow::nullNewUserAttribute
 * @return true->esiste un campo vuoto, false-> tutti i campi sono valorizzati
 */
bool MainWindow::nullNewUserAttribute(){
    return ui->lineEdit_nu_name->text().isEmpty() ||
           ui->lineEdit_nu_surname->text().isEmpty() ||
           ui->lineEdit_nu_email->text().isEmpty() ||
           ui->lineEdit_pathpic->text().isEmpty() ||
           ui->lineEdit_nu_psw->text().isEmpty() ||
           ui->lineEdit_nu_cellnumber->text().isEmpty();
}
/**
 * Verifica che i campi del nuovo intervento da inserire non siano vuoti
 *
 * @brief MainWindow::nullNewOperationAttribute
 * @return true->esiste un campo vuoto, false-> tutti i campi sono valorizzati
 */

bool MainWindow::nullNewOperationAttribute()
{
    return ui->lineEdit_op_name->text().isEmpty() ||
           ui->lineEdit_op_address->text().isEmpty() ||
           ui->lineEdit_op_lat->text().isEmpty() ||
           ui->lineEdit_op_lng->text().isEmpty() ||
           ui->lineEdit_op_petitioner->text().isEmpty() ||
           ui->lineEdit_op_cellnumber->text().isEmpty();
}

/**
 * Reset campi nuovo utente
 *
 * @brief MainWindow::clearNewUserAttribute
 */
void MainWindow::clearNewUserAttribute(){
    ui->lineEdit_nu_name->clear();
    ui->lineEdit_nu_surname->clear();
    ui->dateEdit_nu_birthday->clear();
    ui->lineEdit_nu_email->clear();
    ui->lineEdit_nu_psw->clear();
    ui->lineEdit_pathpic->clear();
    ui->lineEdit_nu_cellnumber->clear();
    ui->radioButton_nu_admin->setChecked(1);
}

/**
 * Reset campi nuovo intervento
 *
 * @brief MainWindow::clearNewOperationAttribute
 */


void MainWindow::clearNewOperationAttribute(){
    ui->lineEdit_op_name->clear();
    ui->lineEdit_op_address->clear();
    ui->lineEdit_op_lat->clear();
    ui->lineEdit_op_lng->clear();
    ui->lineEdit_op_petitioner->clear();
    ui->dateTimeEdit_op_start->clear();
    ui->dateTimeEdit_op_stop->clear();
}

void MainWindow::on_commandLinkButton_home_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_info->setCurrentIndex(0);
}


void MainWindow::on_commandLinkButton_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_info->setCurrentIndex(0);
}


void MainWindow::on_commandLinkButton_home_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_info->setCurrentIndex(0);
}


void MainWindow::on_commandLinkButton_home_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_info->setCurrentIndex(0);
}

