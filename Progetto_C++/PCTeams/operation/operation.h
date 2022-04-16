#ifndef OPERATION_H
#define OPERATION_H

#include <QString>
#include <QGeoCoordinate>
#include <QDateTime>
#include <vector>
#include <memory>
#include "user/foreman.h"
#include "team/team.h"


enum class COLOR : char{
    RED = 'R',
    ORANGE = 'O',
    GREEN = 'G'
};

class Operation
{
public:
    Operation();
    Operation(const QString &name, const QString &address, QGeoCoordinate *coordinate, const QString &petitioner, const QString &cellnumber, COLOR color, const std::shared_ptr<User> &leader, const std::shared_ptr<Team> &team, QDateTime *starttime, QDateTime *finishtime);

    ~Operation(){
        delete coordinate;
        delete starttime;
        delete finishtime;
    }

    int getIdoperation() const;
    const QString &getName() const;
    void setName(const QString &newName);
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
    const std::shared_ptr<User> &getLeader() const;
    void setLeader(const std::shared_ptr<User> &newLeader);
    const std::shared_ptr<Team> &getTeam() const;
    void setTeam(const std::shared_ptr<Team> &newTeam);
    QDateTime *getStarttime() const;
    void setStarttime(QDateTime *newStarttime);
    QDateTime *getFinishtime() const;
    void setFinishtime(QDateTime *newFinishtime);

private:
    static int idprog; // numero progessivo interventi
    int idoperation;
    QString name;
    QString address;
    QGeoCoordinate* coordinate;
    QString petitioner;
    QString cellnumber;
    COLOR color;
    std::shared_ptr<User> leader;
    std::shared_ptr<Team> team;
    QDateTime* starttime;
    QDateTime* finishtime;
    //TODO add report reference
};

#endif // OPERATION_H
