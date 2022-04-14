#ifndef OPERATION_H
#define OPERATION_H

#include <QString>
#include <QGeoCoordinate>
#include <QDateTime>
#include <vector>
#include <memory>
#include "user/volunteer.h"

enum class COLOR : char{
    RED = 'R',
    ORANGE = 'O',
    GREEN = 'G'
};

class Operation
{
public:
    Operation();
    Operation(const QString &address, QGeoCoordinate *coordinate, const QString &petitioner, const QString &cellnumber, COLOR color, int idforeman, QDateTime *starttime, QDateTime *finishtime);

    ~Operation(){
        delete coordinate;
        delete starttime;
        delete finishtime;
    }

    const QString &getAddress() const;
    void setAddress(const QString &newAddress);
    QGeoCoordinate *getCoordinate() const;
    void setCoordinate(QGeoCoordinate *newCoordinate);
    const QString &getPetitioner() const;
    void setPetitioner(const QString &newPetitioner);
    const QString &getCellnumber() const;
    void setCellnumber(const QString &newCellnumber);
    COLOR getColor() const;
    void setColor(COLOR newColor);
    int getIdforeman() const;
    void setIdforeman(int newIdforeman);
    QDateTime *getStarttime() const;
    void setStarttime(QDateTime *newStarttime);
    QDateTime *getFinishtime() const;
    void setFinishtime(QDateTime *newFinishtime);
    const std::vector<std::shared_ptr<Volunteer> > &getPartecipants() const;
    void setPartecipants(const std::vector<std::shared_ptr<Volunteer> > &newPartecipants);

    int getIdoperation() const;

private:
    static int idprog; // numero progessivo interventi
    int idoperation;
    QString address;
    QGeoCoordinate* coordinate;
    QString petitioner;
    QString cellnumber;
    COLOR color;
    int idforeman;
    QDateTime* starttime;
    QDateTime* finishtime;
    std::vector<std::shared_ptr<Volunteer>> partecipants;
    //TODO add report reference
};

#endif // OPERATION_H
