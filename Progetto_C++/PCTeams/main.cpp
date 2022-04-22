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
#include "operation/operationrepository.h"
#include "operation/operation.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainwindow;

    LoginForm loginform(nullptr, &mainwindow);

    loginform.show();

    TeamRepository::getInstance()->insertTeam(new Team("SVTeam","Sovere",new QGeoCoordinate(45.81666564941406,10.033333778381348)));
    TeamRepository::getInstance()->insertTeam(new Team("BGTeam","Bergamo",new QGeoCoordinate(45.81666564941234,10.033333778386548)));

    UserRepository::getInstance()->insertUser(new Administrator("pippo","Giovanni","Carne", new QDate(1987,07,25), "giovanni@carne.it", "3698765987", 'M',
                                                                new QPixmap("C:/Users/Matteo Verzeroli/Desktop/PA Project/Progetto_C++/PCTeams/img/avatar.png")));
    UserRepository::getInstance()->insertUser(new Foreman("pippo","Matteo","Verzeroli", new QDate(1999,07,18), "matteo.verzeroli@unibg.it",
                                                          "3407595684", 'M', new QPixmap("C:/Users/Matteo Verzeroli/Desktop/PA Project/Progetto_C++/PCTeams/img/avatar.png"),
                                                          TeamRepository::getInstance()->getTeamById(0)));

    UserRepository::getInstance()->insertUser(new Volunteer("pippo","Arnaldo","Rossi", new QDate(1965,6,5),"arna@rossi.com","365985633",
                                                            'M',new QPixmap("C:/Users/Matteo Verzeroli/Desktop/PA Project/Progetto_C++/PCTeams/img/avatar.png"),
                                                            TeamRepository::getInstance()->getTeamById(0)));
    UserRepository::getInstance()->insertUser(new Volunteer("pippo","Federica","Verdi", new QDate(1978,10,10),"federica@verdi.com","36956486520",
                                                            'F',new QPixmap("C:/Users/Matteo Verzeroli/Desktop/PA Project/Progetto_C++/PCTeams/img/avatar.png"),
                                                            TeamRepository::getInstance()->getTeamById(0)));
    UserRepository::getInstance()->insertUser(new Volunteer("pippo","Giuseppe","Bianchi", new QDate(1985,9,5),"giuseppe@bianchi.com","369563214569",
                                                            'M',new QPixmap("C:/Users/Matteo Verzeroli/Desktop/PA Project/Progetto_C++/PCTeams/img/avatar.png"),
                                                            TeamRepository::getInstance()->getTeamById(0)));
    UserRepository::getInstance()->insertUser(new Volunteer("pippo","Davide","Carrara", new QDate(1996,8,5),"davide@carrara.com","3695632456",
                                                            'M',new QPixmap("C:/Users/Matteo Verzeroli/Desktop/PA Project/Progetto_C++/PCTeams/img/avatar.png"),
                                                            TeamRepository::getInstance()->getTeamById(0)));
    UserRepository::getInstance()->insertUser(new Volunteer("pippo","Andrea","Carducci", new QDate(1966,5,30),"andrea@carducci.com","361265487",
                                                            'F',new QPixmap("C:/Users/Matteo Verzeroli/Desktop/PA Project/Progetto_C++/PCTeams/img/avatar.png"),
                                                            TeamRepository::getInstance()->getTeamById(0)));

    OperationRepository::getInstance()->insertOperation(new Operation("Sistemazione valle","Via Giuseppe Verdi",
                                                                      new QGeoCoordinate(45.81666564941406,10.033333778381348),
                                                                      "Gianni Floreale","340589613", COLOR::GREEN,
                                                                      UserRepository::getInstance()->getUserById(1000),
                                                                      TeamRepository::getInstance()->getTeamById(0),
                                                                      new QDateTime(QDateTime::currentDateTime()),
                                                                      new QDateTime(QDateTime::currentDateTime())));
    OperationRepository::getInstance()->insertOperation(new Operation("Sistemazione valle","Via Giuseppe Verdi",
                                                                      new QGeoCoordinate(45.81666564941406,10.033333778381348),
                                                                      "Gianni Floreale","340589613", COLOR::GREEN,
                                                                      UserRepository::getInstance()->getUserById(1000),
                                                                      TeamRepository::getInstance()->getTeamById(1),
                                                                      new QDateTime(QDateTime::currentDateTime()),
                                                                      new QDateTime(QDateTime::currentDateTime())));
    return a.exec();
}
