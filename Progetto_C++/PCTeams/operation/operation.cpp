#include "operation.h"

int Operation::idprog = 0;

Operation::Operation()
{

}

Operation::Operation(const QString &name, const QString &address, QGeoCoordinate *coordinate, const QString &petitioner, const QString &cellnumber, COLOR color, const std::shared_ptr<User> leader, const std::shared_ptr<Team> team, QDateTime *starttime, QDateTime *finishtime) :
    idoperation(idprog++),
    name(name),
    address(address),
    coordinate(coordinate),
    petitioner(petitioner),
    cellnumber(cellnumber),
    color(color),
    leader(leader),
    team(team),
    starttime(starttime),
    finishtime(finishtime)
{}

QString Operation::toString()
{
    return  "Intervento n°: " +
            QString::number(idoperation) + " " +
            name + " |" + address + " " +
            coordinate->toString() + " |" +
            "Inizio: " + starttime->toString("dd/MM/yyyy hh:mm:ss") + " " +
            "Fine: " + finishtime->toString("dd/MM/yyyy hh:mm:ss") + "| " +
            "|Richiedente: " + " " + petitioner + " " +
            cellnumber + " " + colorToString(color) + " " +
            "|Capo Intervento: " + leader->toString() + " " +
            "|Squadra: " + team->getName();
}

int Operation::getIdoperation() const
{
    return idoperation;
}

const QString &Operation::getName() const
{
    return name;
}

void Operation::setName(const QString &newName)
{
    name = newName;
}

const QString &Operation::getAddress() const
{
    return address;
}

void Operation::setAddress(const QString &newAddress)
{
    address = newAddress;
}

QGeoCoordinate *Operation::getCoordinate() const
{
    return coordinate;
}

void Operation::setCoordinate(QGeoCoordinate *newCoordinate)
{
    coordinate = newCoordinate;
}

const QString &Operation::getPetitioner() const
{
    return petitioner;
}

void Operation::setPetitioner(const QString &newPetitioner)
{
    petitioner = newPetitioner;
}

const QString &Operation::getCellnumber() const
{
    return cellnumber;
}

void Operation::setCellnumber(const QString &newCellnumber)
{
    cellnumber = newCellnumber;
}

COLOR Operation::getColor() const
{
    return color;
}

void Operation::setColor(COLOR newColor)
{
    color = newColor;
}

const std::shared_ptr<User> &Operation::getLeader() const
{
    return leader;
}

void Operation::setLeader(const std::shared_ptr<User> &newLeader)
{
    leader = newLeader;
}

const std::shared_ptr<Team> &Operation::getTeam() const
{
    return team;
}

void Operation::setTeam(const std::shared_ptr<Team> &newTeam)
{
    team = newTeam;
}

QDateTime *Operation::getStarttime() const
{
    return starttime;
}

void Operation::setStarttime(QDateTime *newStarttime)
{
    starttime = newStarttime;
}

QDateTime *Operation::getFinishtime() const
{
    return finishtime;
}

void Operation::setFinishtime(QDateTime *newFinishtime)
{
    finishtime = newFinishtime;
}

const QString Operation::colorToString(COLOR c)
{
    switch (c)
    {
        case COLOR::RED:   return QString("ROSSO");
        case COLOR::ORANGE:   return QString("ARANCIO");
        case COLOR::GREEN: return QString("VERDE");
        default : return QString("");
    }
}

const QIcon Operation::colorToIcon(COLOR c)
{
    switch (c)
    {
        case COLOR::RED:   return QIcon(":/img/img/red");
        case COLOR::ORANGE:   return QIcon(":/img/img/orange");
        case COLOR::GREEN: return QIcon(":/img/img/green");
        default : return QIcon("");
    }
}

COLOR Operation::stringToColor(QString s)
{
    if(s == "ROSSO")
        return COLOR::RED;
    else if(s == "ARANCIO")
        return COLOR::ORANGE;
    else
        return COLOR::GREEN;
}
