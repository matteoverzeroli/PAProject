#include "volunteer.h"
#include "operation/operationrepository.h"
#include "operation/operation.h"

Volunteer::Volunteer(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, QPixmap* picture,  std::shared_ptr<Team> team) : User(password, name, surname, birthday, email, cellnumber, sex, picture),
    team(team)
{}

Volunteer::Volunteer()
{

}

std::shared_ptr<Team> Volunteer::getTeam() const
{
    return team;
}

void Volunteer::setTeam(std::shared_ptr<Team> newTeam)
{
    team = newTeam;
}

void Volunteer::initializeMainWindow(Ui::MainWindow *ui)
{
    User::initializeMainWindow(ui);

    ui->label_team_id->setText(QString::number(team->getIdteam()));
    ui->label_team_name->setText(team->getName());
    ui->label_team_area->setText(team->getAreaname());
    ui->label_team_lat->setText(QString::number(team->getCoordinate()->latitude(),'f',14));
    ui->label_team_lng->setText(QString::number(team->getCoordinate()->longitude(),'f',14));

    ui->label_team->show();
    ui->formWidget_team->show();

}
/**
 * Il volontario potrà visualizzare solamente gli interventi della propria squadra
 *
 * @brief Volunteer::populateOperationList
 * @param ui
 */

void Volunteer::populateOperationList(QListWidget *oplist, const QDate &date)
{
    oplist->clear();

    auto operations = OperationRepository::getInstance()->getAllOperation(team->getIdteam(), date);
    for(auto it = operations.begin(); it != operations.end(); ++it){
        oplist->addItem((*it)->toString());
    }
}

QString Volunteer::toString()
{
    return User::toString() + " |Team: " + team->toString();
}
