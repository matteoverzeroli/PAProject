#include "user/userrepository.h"
#include <QString>
#include <memory>
#include <iostream>
#include "helpers.h"

UserRepository* UserRepository::instance = 0;

UserRepository::UserRepository(){
    usertable = std::map<int, std::shared_ptr<User>>();
}

UserRepository* UserRepository::getInstance(){
    if(instance == 0){
        instance = new UserRepository();
    }
    return instance;
}

std::shared_ptr<User> UserRepository::getUserById(int iduser){
    auto it = usertable.find(iduser);
    if(it != usertable.end()){
        return it->second;
    }
    else{
        return std::shared_ptr<User>(nullptr);
    }
}

std::vector<std::shared_ptr<User> > UserRepository::getAllUser()
{
    return Helpers::extract_values_from_map(usertable);
}

void UserRepository::insertUser(User* user){
    std::shared_ptr<User> new_user(user);
    usertable[user->getIduser()] = new_user;
}

bool UserRepository::removeUser(int iduser)
{
    return usertable.erase(iduser);
}
