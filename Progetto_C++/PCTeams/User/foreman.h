#ifndef FOREMAN_H
#define FOREMAN_H

#include "user/administrator.h"
#include "user/volunteer.h"

class Foreman: public Administrator, public Volunteer
{
public:
    Foreman(const QString &password, const QString &name, const QString &surname, const QDate &birthday, const QString &email, const QString &cellnumber, const QChar &sex, Team *team = nullptr);
    Foreman();
    virtual ~Foreman(){
        std::cout << "delete foreman\n";
    }
};

#endif // FOREMAN_H