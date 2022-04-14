#include "administrator.h"
#include <iostream>

Administrator::Administrator(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex) : User(password, name, surname, birthday, email, cellnumber, sex)
{}

Administrator::Administrator()
{

}

void Administrator::initializeMainWindow(Ui::MainWindow *ui)
{
    User::initializeMainWindow(ui);
}
