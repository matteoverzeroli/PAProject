#include "team.h"

int Team::idprog = 0;

Team::Team() : idteam(-1), coordinate(nullptr){}

Team::Team(const QString &name, const QString &areaname, QGeoCoordinate *coordinate) : idteam(idprog++),
    name(name),
    areaname(areaname),
    coordinate(coordinate)
{}

int Team::getIdteam() const
{
    return idteam;
}

void Team::setIdteam(int newIdteam)
{
    idteam = newIdteam;
}

const QString &Team::getName() const
{
    return name;
}

void Team::setName(const QString &newName)
{
    name = newName;
}

const QString &Team::getAreaname() const
{
    return areaname;
}

void Team::setAreaname(const QString &newAreaname)
{
    areaname = newAreaname;
}

const QGeoCoordinate *Team::getCoordinate() const
{
    return coordinate;
}

void Team::setCoordinate(QGeoCoordinate *newCoordinate)
{
    coordinate = newCoordinate;
}

QString Team::toString()
{
    return QString::number(idteam) + " " + name + " " + areaname + " " + coordinate->toString();
}
