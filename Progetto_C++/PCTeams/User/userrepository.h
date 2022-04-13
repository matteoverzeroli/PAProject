#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <map>
#include <QString>
#include <memory>
#include <user/user.h>

class UserRepository
{
public:
    static UserRepository* getInstance();
    std::shared_ptr<User> getUserById(int userid);
    void insertUser(User* user);
    bool removeUser(int userid);
    void printTable();

    ~UserRepository(){
        std::cout<< "delete userrepo" <<std::endl;
    }

private:
    std::map<int, std::shared_ptr<User>> usertable;
    static UserRepository* instance;

    UserRepository();
};

#endif // USERREPOSITORY_H
