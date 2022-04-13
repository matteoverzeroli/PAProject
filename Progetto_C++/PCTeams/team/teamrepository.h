#ifndef TEAMREPOSITORY_H
#define TEAMREPOSITORY_H

#include <memory>
#include <map>
#include "team/team.h"

class TeamRepository
{
public:
    static TeamRepository* getInstance();
    std::shared_ptr<Team> getUserById(int idteam);
    void insertTeam(Team* team);
    bool removeTeam(int idteam);

    ~TeamRepository();

private:
    std::map<int, std::shared_ptr<Team>> teamtable;
    static TeamRepository* instance;

    TeamRepository();
};

#endif // TEAMREPOSITORY_H
