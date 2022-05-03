#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QGeoCoordinate>
#include <iostream>

class Team
{
public:
    Team(); //costruttore di default utilizzato solamente per creare team temporanei
    Team(const QString &name, const QString &areaname, QGeoCoordinate* coordinate);

    ~Team(){
        if(coordinate != nullptr)
            delete coordinate;
        std::cout << ("deleted team\n");
    }

    int getIdteam() const;
    void setIdteam(int newIdteam);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getAreaname() const;
    void setAreaname(const QString &newAreaname);
    const QGeoCoordinate* getCoordinate() const;
    void setCoordinate(QGeoCoordinate *newCoordinate);

    QString toString();

private:
    static int idprog; // numero progessivo team

    int idteam;
    QString name;
    QString areaname;
    QGeoCoordinate* coordinate;
};

#endif // TEAM_H
