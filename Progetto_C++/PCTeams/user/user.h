#ifndef USER_H
#define USER_H

#include <QString>
#include <QChar>
#include <QDate>
#include "team/team.h"
#include <iostream>
#include "ui_mainwindow.h"

class User
{
public:
    User(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, QPixmap* picture);

    User();

    virtual ~User(){
        std::cout << "delete user\n";
        delete picture;
    }

    int getIduser() const;
    void setIduser(int newIduser);
    const QString &getPassword() const;
    void setPassword(const QString &newPassword);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getSurname() const;
    void setSurname(const QString &newSurname);
    const QDate *getBirthday() const;
    void setBirthday(QDate *newBirthday);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    const QString &getCellnumber() const;
    void setCellnumber(const QString &newCellnumber);
    const QChar &getSex() const;
    void setSex(const QChar &newSex);

    virtual void initializeMainWindow(Ui::MainWindow* ui);
    virtual std::shared_ptr<Team> getTeam() const = 0;
    virtual QString toString();


protected:
    int iduser;
    QString password;
    QString name;
    QString surname;
    QDate* birthday;
    QString email;
    QString cellnumber;
    QChar sex;
    QPixmap* picture;

private:
    static int idprog; // numero progessivo utente
    friend std::ostream& operator<<(std::ostream&, const User&);
};

#endif // USER_H
