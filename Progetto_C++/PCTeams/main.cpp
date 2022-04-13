#include "mainwindow/mainwindow.h"
#include <QApplication>
#include "loginform/loginform.h"
#include "user/userrepository.h"
#include "user/user.h"
#include "user/administrator.h"
#include "user/foreman.h"
#include "user/volunteer.h"
#include "team/team.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainwindow;

    LoginForm loginform(nullptr, &mainwindow);

    loginform.show();

    QDate data (1999,07,18);
    User user("pippo","matteo","verzeroli", new QDate(1999,07,18), "matteoverzeroli@live.it", "3407580457", 'm');

    Foreman foreman("pippo","Luca","verzeroli", new QDate(1999,07,18), "matteoverzeroli@live.it", "3407580457", 'm');

    Team* team = new Team("SVTeam","sovere",new QGeoCoordinate(45.81666564941406,45.81666564941406));


    UserRepository::getInstance()->insertUser(new User(user));
    UserRepository::getInstance()->insertUser(new Foreman(foreman));

    cout<<"fine\n";

    return a.exec();
}
