#include "administrator.h"
#include <iostream>
#include "user/userrepository.h"
#include "user/foreman.h"
#include "team/teamrepository.h"
#include <QString>

Administrator::Administrator(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, QPixmap* picture) : User(password, name, surname, birthday, email, cellnumber, sex, picture                                                                                                                                                                                         )
{}

Administrator::Administrator()
{

}

void Administrator::initializeMainWindow(Ui::MainWindow *ui)
{
    User::initializeMainWindow(ui);

    ui->commandLinkButton_deleteuser->show();
    ui->commandLinkButton_newuser->show();
    ui->commandLinkButton_showusers->show();
}

void Administrator::addNewUser(User *user)
{
    UserRepository::getInstance()->insertUser(user);
}

void Administrator::addNewUser(Volunteer *volunteer, int idteam)
{
    volunteer->setTeam(TeamRepository::getInstance()->getTeamById(idteam));
    UserRepository::getInstance()->insertUser(volunteer);
}

void Administrator::populateComboBoxTeams(QComboBox *comboBox, bool isForeman)
{
    auto teams = TeamRepository::getInstance()->getAllTeam();

    if(isForeman){ //se devo inserire un caposquadra, mostrerò solamente le squadre che non hanno assegnato ancora un caposqudra
        auto users = UserRepository::getInstance()->getAllUser();

        for(auto it = users.begin(); it != users.end(); ++it){
            std::shared_ptr<Foreman> foreman =
                           std::dynamic_pointer_cast<Foreman> (*it);
            if(foreman != nullptr){
                teams.erase(std::find(teams.begin(),teams.end(), foreman->getTeam()));
            }
        }
    }

    for(auto it = teams.begin(); it != teams.end(); ++it){
        comboBox->addItem(QString::number((*it)->getIdteam()) + " " + (*it)->getName());
    }

}

void Administrator::populateListBoxUsers(QListWidget *listWidget, int idteam) //-1 seleziona gli amministratori
{
    QString result;

    auto users = UserRepository::getInstance()->getAllUser();

    for(auto it = users.begin(); it != users.end(); ++it){

        std::shared_ptr<Foreman> foreman =
                       std::dynamic_pointer_cast<Foreman> (*it);
        if(foreman != nullptr){
            result = (idteam == foreman->getTeam()->getIdteam()) ? foreman->toString() : "";
        }
        else{
            std::shared_ptr<Administrator> admin =
                           std::dynamic_pointer_cast<Administrator> (*it);
            if(admin != nullptr && idteam == -1){
                result = admin->toString();
            }
            else{
                std::shared_ptr<Volunteer> volunteer =
                               std::dynamic_pointer_cast<Volunteer> (*it);
                if(volunteer != nullptr){
                    result = (idteam == volunteer->getTeam()->getIdteam()) ? volunteer->toString() : "";
                }
            }
        }

        if(!result.isEmpty()){
            listWidget->addItem(result);
        }
    }
}

void Administrator::deleteUser(int iduser)
{
    UserRepository::getInstance()->removeUser(iduser);
}
