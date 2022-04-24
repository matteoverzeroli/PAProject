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