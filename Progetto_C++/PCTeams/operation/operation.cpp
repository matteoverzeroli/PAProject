#include "operation.h"

int Operation::idprog = 0;

Operation::Operation()
{

}

Operation::Operation(const QString &address, QGeoCoordinate *coordinate, const QString &petitioner, const QString &cellnumber, COLOR color, int idforeman, QDateTime *starttime, QDateTime *finishtime) :
    idoperation(idprog++),
    address(address),
    coordinate(coordinate),
    petitioner(petitioner),
    cellnumber(cellnumber),
    color(color),
    idforeman(idforeman),
    starttime(starttime),
    finishtime(finishtime)
{
    partecipants = std::vector<std::shared_ptr<Volunteer>>();
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

int Operation::getIdforeman() const
{
    return idforeman;
}

void Operation::setIdforeman(int newIdforeman)
{
    idforeman = newIdforeman;
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

const std::vector<std::shared_ptr<Volunteer> > &Operation::getPartecipants() const
{
    return partecipants;
}

void Operation::setPartecipants(const std::vector<std::shared_ptr<Volunteer> > &newPartecipants)
{
    partecipants = newPartecipants;
}

int Operation::getIdoperation() const
{
    return idoperation;
}
