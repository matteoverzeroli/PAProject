#ifndef TEAMREPOSITORY_H
#define TEAMREPOSITORY_H

#include <memory>
#include <map>
#include <vector>
#include "team/team.h"

class TeamRepository
{
public:
    static TeamRepository* getInstance();
    std::shared_ptr<Team> getTeamById(int idteam);
    std::vector<std::shared_ptr<Team>> getAllTeam();
    void insertTeam(Team* team);
    bool removeTeam(int idteam);

    ~TeamRepository();
private:
    std::map<int, std::shared_ptr<Team>> teamtable;
    static TeamRepository* instance;

    TeamRepository();
};

#endif // TEAMREPOSITORY_H
