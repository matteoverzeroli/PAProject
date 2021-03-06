#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <map>
#include <vector>
#include <QString>
#include <memory>
#include <user/user.h>

class UserRepository
{
public:
    static UserRepository* getInstance();
    std::shared_ptr<User> getUserById(int iduser);
    std::vector<std::shared_ptr<User>> getAllUser();
    void insertUser(User* user);
    bool removeUser(int iduser);

    ~UserRepository();

private:
    std::map<int, std::shared_ptr<User>> usertable;
    static UserRepository* instance;

    UserRepository();
};

#endif // USERREPOSITORY_H
