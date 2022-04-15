#include "mainwindow/mainwindow.h"
#include <QApplication>
#include "loginform/loginform.h"
#include "user/userrepository.h"
#include "user/user.h"
#include "user/administrator.h"
#include "user/foreman.h"
#include "user/volunteer.h"
#include "team/team.h"
#include "team/teamrepository.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainwindow;

    LoginForm loginform(nullptr, &mainwindow);

    loginform.show();

    TeamRepository::getInstance()->insertTeam(new Team("SVTeam","sovere",new QGeoCoordinate(45.81666564941406,10.033333778381348)));
    TeamRepository::getInstance()->insertTeam(new Team("BGTeam","bergamo",new QGeoCoordinate(45.81666564941234,10.033333778386548)));

    UserRepository::getInstance()->insertUser(new Administrator("pippo","matteo","verzeroli", new QDate(1999,07,18), "matteoverzeroli@live.it", "3407580457", 'M'));
    UserRepository::getInstance()->insertUser(new Foreman("pippo","Luca","verzeroli", new QDate(1999,07,18), "matteoverzeroli@live.it",
                                                          "3407580457", 'M',TeamRepository::getInstance()->getTeamById(0)));
    return a.exec();
}
