#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QGeoCoordinate>

class Team
{
public:
    Team();
    Team(const QString &name, const QString &areaname, QGeoCoordinate* coordinate);

    ~Team(){
        delete coordinate;
    }

    int getIdteam() const;
    void setIdteam(int newIdteam);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getAreaname() const;
    void setAreaname(const QString &newAreaname);
    const QGeoCoordinate* getCoordinate() const;
    void setCoordinate(QGeoCoordinate *newCoordinate);

private:
    static int idprog; // numero progessivo team

    int idteam;
    QString name;
    QString areaname;
    QGeoCoordinate* coordinate;
};

#endif // TEAM_H
