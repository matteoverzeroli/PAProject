#include "user/user.h"

int User::idprog = 1000;

int User::getIduser() const
{
    return iduser;
}

void User::setIduser(int newIduser)
{
    iduser = newIduser;
}

const QString &User::getPassword() const
{
    return password;
}

void User::setPassword(const QString &newPassword)
{
    password = newPassword;
}

const QString &User::getName() const
{
    return name;
}

void User::setName(const QString &newName)
{
    name = newName;
}

const QString &User::getSurname() const
{
    return surname;
}

void User::setSurname(const QString &newSurname)
{
    surname = newSurname;
}

const QDate *User::getBirthday() const
{
    return birthday;
}

void User::setBirthday(QDate *newBirthday)
{
    birthday = newBirthday;
}

const QString &User::getEmail() const
{
    return email;
}

void User::setEmail(const QString &newEmail)
{
    email = newEmail;
}

const QString &User::getCellnumber() const
{
    return cellnumber;
}

void User::setCellnumber(const QString &newCellnumber)
{
    cellnumber = newCellnumber;
}

const QChar &User::getSex() const
{
    return sex;
}

void User::setSex(const QChar &newSex)
{
    sex = newSex;
}

User::User(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex) :
    iduser(idprog++),
    password(password),
    name(name),
    surname(surname),
    birthday(birthday),
    email(email),
    cellnumber(cellnumber),
    sex(sex)
{}

User::User()
{

}


std::ostream& operator<<(std::ostream &strm, const User &u) {
  return strm << "User: " << u.iduser << " " << u.name.toStdString() << " " << u.surname.toStdString();
}
