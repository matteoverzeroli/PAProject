#include "foreman.h"
#include "operation/operationrepository.h"
#include "user/userrepository.h"

Foreman::Foreman(const QString &password, const QString &name, const QString &surname,
                 QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, QPixmap* picture, std::shared_ptr<Team> team) :
    User(password, name, surname, birthday, email, cellnumber, sex, picture),
    Administrator(password, name, surname, birthday, email, cellnumber, sex, picture),
    Volunteer(password, name, surname, birthday, email, cellnumber, sex, picture, team)
{}

Foreman::Foreman()
{

}

void Foreman::initializeMainWindow(Ui::MainWindow *ui)
{
    Volunteer::initializeMainWindow(ui);

    ui->commandLinkButton_deleteuser->show();
    ui->commandLinkButton_newuser->show();
    ui->commandLinkButton_showusers->show();
    ui->pushButton_op_newop->show();
    ui->pushButton_op_add->show();
}

void Foreman::populateComboBoxTeams(QComboBox* comboBox, bool isForeman)
{
    if(isForeman){
        Administrator::populateComboBoxTeams(comboBox, isForeman);
    }
    else{
        comboBox->addItem(QString::number(team->getIdteam()) + " " + team->getName());
    }
}

void Foreman::populateOperationList(QListWidget *oplist, const QDate &date)
{
    oplist->clear();

    auto operations = OperationRepository::getInstance()->getAllOperation(date);
    for(auto it = operations.begin(); it != operations.end(); ++it){
        oplist->addItem((*it)->toString());
    }
}

std::shared_ptr<Team> Foreman::getTeam() const
{
    return Volunteer::getTeam();
}

void Foreman::populateVolunteerComboBox(QComboBox *comboBox)
{
    auto users = UserRepository::getInstance()->getAllUser();

    for(auto it = users.begin(); it != users.end(); ++it){
        std::shared_ptr<Volunteer> volunteer =
                       std::dynamic_pointer_cast<Volunteer> (*it);
        if(volunteer != nullptr && volunteer->getTeam()->getIdteam() == team->getIdteam()){
            comboBox->addItem(QString::number(volunteer->getIduser()) + " " + volunteer->getName() + " " + volunteer->getSurname());
        }
    }
}

void Foreman::addNewOperation(Operation *newop)
{
    OperationRepository::getInstance()->insertOperation(newop);
}
