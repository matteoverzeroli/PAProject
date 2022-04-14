#include "administrator.h"
#include <iostream>
#include <user/userrepository.h>

Administrator::Administrator(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex) : User(password, name, surname, birthday, email, cellnumber, sex)
{}

Administrator::Administrator()
{

}

void Administrator::initializeMainWindow(Ui::MainWindow *ui)
{
    User::initializeMainWindow(ui);
    ui->stackedWidget_info->setCurrentIndex(0);
}

void Administrator::addNewUser(User *user)
{
    UserRepository::getInstance()->insertUser(user);
}
