#include "foreman.h"

Foreman::Foreman(const QString &password, const QString &name, const QString &surname,
                 const QDate &birthday, const QString &email, const QString &cellnumber, const QChar &sex, Team *team) :
    User(password, name, surname, birthday, email, cellnumber, sex),
    Administrator(password, name, surname, birthday, email, cellnumber, sex),
    Volunteer(password, name, surname, birthday, email, cellnumber, sex, team)
{}

Foreman::Foreman()
{

}
