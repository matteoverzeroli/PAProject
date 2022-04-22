#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user/user.h"
#include <user/volunteer.h>

class Administrator : virtual public User
{

public:
    Administrator(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, QPixmap* picture);
    Administrator();
    virtual ~Administrator(){
        std::cout<< "delete admin \n";
    };

    virtual void initializeMainWindow(Ui::MainWindow* ui);
    virtual void addNewUser(User* user);
    virtual void addNewUser(Volunteer* volunteer, int idteam);
    virtual void populateComboBoxTeams(QComboBox* comboBox, bool isForeman);
    virtual void populateListBoxUsers(QListWidget* listWidget, int idteam = -1);
    virtual std::shared_ptr<Team> getTeam() const;
    virtual void deleteUser(int iduser);
};

#endif // ADMINISTRATOR_H
