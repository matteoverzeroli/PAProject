#include "volunteer.h"


Volunteer::Volunteer(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, Team *team) : User(password, name, surname, birthday, email, cellnumber, sex),
    team(team)
{}

Volunteer::Volunteer()
{

}

Team *Volunteer::getTeam() const
{
    return team;
}

void Volunteer::setTeam(Team *newTeam)
{
    team = newTeam;
}
