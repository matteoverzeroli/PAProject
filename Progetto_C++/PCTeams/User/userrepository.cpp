#include "user/userrepository.h"
#include <QString>
#include <memory>
#include <iostream>

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

void UserRepository::insertUser(User* user){
    std::shared_ptr<User> new_user(user);
    usertable[user->getIduser()] = new_user;
}

bool UserRepository::removeUser(int iduser)
{
    return usertable.erase(iduser);
}

void UserRepository::printTable(){
    for(auto it = usertable.begin(); it!= usertable.end(); ++it){
        std::cout << it->first <<"|"<<*(it->second) << std::endl;
    }

}
