#ifndef VOLUNTEER_H
#define VOLUNTEER_H

#include "user/user.h"
#include "team/team.h"

class Volunteer : virtual public User
{
public:
    Volunteer(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, Team *team = nullptr);
    Volunteer();

    virtual ~Volunteer(){
        delete team;
        delete birthday;
        std:: cout << "delete volunteer\n";
    }

    Team *getTeam() const;
    void setTeam(Team *newTeam);

    virtual void initializeMainWindow(Ui::MainWindow* ui);

protected:
    Team* team;
};

#endif // VOLUNTEER_H
