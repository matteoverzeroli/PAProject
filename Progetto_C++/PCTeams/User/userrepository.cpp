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

std::shared_ptr<User> UserRepository::getUserById(int userid){
    auto it = usertable.find(userid);
    if(it != usertable.end()){
        return it->second;
    }
    else{
        return std::shared_ptr<User>(nullptr);
    }
}

void UserRepository::insertUser(User& user){
    std::shared_ptr<User> new_user(new User(user));
    usertable[user.getUserid()] = new_user;
}

void UserRepository::printTable(){
    for(auto it = usertable.begin(); it!= usertable.end(); ++it){
        std::cout << it->first <<"|"<<*(it->second) << std::endl;
    }

}
