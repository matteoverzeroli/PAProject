#ifndef VOLUNTEER_H
#define VOLUNTEER_H

#include "user/user.h"
#include "team/team.h"
#include <memory>

class Volunteer : virtual public User
{
public:
    Volunteer(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, QPixmap* picture, std::shared_ptr<Team> team = std::shared_ptr<Team>(nullptr));
    Volunteer();

    virtual ~Volunteer(){
        delete birthday;
        std:: cout << "delete volunteer\n";
    }

    std::shared_ptr<Team> getTeam() const;
    void setTeam(std::shared_ptr<Team> newTeam);

    virtual void initializeMainWindow(Ui::MainWindow* ui);
    virtual void populateOperationList(QListWidget *list, const QDate &date);
    virtual QString toString();

protected:
    std::shared_ptr<Team> team;
};

#endif // VOLUNTEER_H
