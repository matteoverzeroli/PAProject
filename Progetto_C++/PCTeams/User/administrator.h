#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user/user.h"

class Administrator : virtual public User
{

public:
    Administrator(const QString &password, const QString &name, const QString &surname, QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex);
    Administrator();
    virtual ~Administrator(){
        std::cout<< "delete admin \n";
    };

    virtual void initializeMainWindow(Ui::MainWindow* ui);
};

#endif // ADMINISTRATOR_H
