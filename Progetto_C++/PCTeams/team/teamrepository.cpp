#include "teamrepository.h"

TeamRepository* TeamRepository::instance = 0;

TeamRepository::TeamRepository()
{
    teamtable = std:: map<int, std::shared_ptr<Team>>();
}

TeamRepository* TeamRepository::getInstance(){
    if(instance == 0){
        instance = new TeamRepository();
    }
    return instance;
}

std::shared_ptr<Team> TeamRepository::getUserById(int idteam)
{
    auto it = teamtable.find(idteam);
    if(it != teamtable.end()){
        return it->second;
    }
    else{
        return std::shared_ptr<Team>(nullptr);
    }
}

void TeamRepository::insertTeam(Team *team)
{
    std::shared_ptr<Team> new_team(team);
    teamtable[team->getIdteam()] = new_team;

}

bool TeamRepository::removeTeam(int idteam)
{
    return teamtable.erase(idteam);
}


