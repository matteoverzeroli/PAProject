#ifndef USER_H
#define USER_H

#include <QString>
#include <QChar>
#include <QDate>
#include "team/team.h"
#include <iostream>

class User
{
private:
    static int progressivo; // numero progessivo utente
    friend std::ostream& operator<<(std::ostream&, const User&);

protected:
    int userid;
    QString password;
    QString name;
    QString surname;
    QDate birthday;
    QString email;
    QString cellnumber;
    QChar sex;

public:
    User(const QString &password, const QString &name, const QString &surname, const QDate &birthday, const QString &email, const QString &cellnumber, const QChar &sex);
    virtual ~User(){
        std::cout << "delete user\n";
    }
    User();

    int getUserid() const;
    void setUserid(int newUserid);
    const QString &getPassword() const;
    void setPassword(const QString &newPassword);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getSurname() const;
    void setSurname(const QString &newSurname);
    const QDate &getBirthday() const;
    void setBirthday(const QDate &newBirthday);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    const QString &getCellnumber() const;
    void setCellnumber(const QString &newCellnumber);
    const QChar &getSex() const;
    void setSex(const QChar &newSex);
};

#endif // USER_H
