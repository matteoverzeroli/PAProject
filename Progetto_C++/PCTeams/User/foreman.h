#ifndef FOREMAN_H
#define FOREMAN_H

#include "user/administrator.h"
#include "user/volunteer.h"

class Foreman: public Administrator, public Volunteer
{
public:
    Foreman(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, std::shared_ptr<Team> team = std::shared_ptr<Team>(nullptr));
    Foreman();
    virtual ~Foreman(){
        std::cout << "delete foreman\n";
    }

    virtual void initializeMainWindow(Ui::MainWindow* ui);
    virtual void populateComboBoxTeams(QComboBox* comboBox, bool isForeman);
};

#endif // FOREMAN_H
