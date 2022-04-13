#ifndef VOLUNTEER_H
#define VOLUNTEER_H

#include "user/user.h"
#include "team/team.h"

class Volunteer : virtual public User
{
public:
    Volunteer(const QString &password, const QString &name, const QString &surname, const QDate &birthday, const QString &email, const QString &cellnumber, const QChar &sex, Team *team = nullptr);
    Volunteer();

    virtual ~Volunteer(){
        delete team;
        std:: cout << "delete volunteer\n";
    }
    Team *getTeam() const;
    void setTeam(Team *newTeam);

protected:
    Team* team;
};

#endif // VOLUNTEER_H