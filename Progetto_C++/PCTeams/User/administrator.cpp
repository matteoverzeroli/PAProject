#include "administrator.h"
#include <iostream>
#include "user/userrepository.h"
#include "user/foreman.h"
#include "team/teamrepository.h"

Administrator::Administrator(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex) : User(password, name, surname, birthday, email, cellnumber, sex)
{}

Administrator::Administrator()
{

}

void Administrator::initializeMainWindow(Ui::MainWindow *ui)
{
    User::initializeMainWindow(ui);
    ui->stackedWidget_info->setCurrentIndex(0);
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
