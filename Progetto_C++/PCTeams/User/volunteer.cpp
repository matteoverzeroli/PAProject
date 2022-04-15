#include "volunteer.h"

Volunteer::Volunteer(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, std::shared_ptr<Team> team) : User(password, name, surname, birthday, email, cellnumber, sex),
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

QString Volunteer::toString()
{
    return User::toString() + " |Team: " + team->toString();
}
