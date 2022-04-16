#ifndef OPERATIONREPOSITORY_H
#define OPERATIONREPOSITORY_H

#include <memory>
#include <map>
#include <vector>
#include <operation/operation.h>

class OperationRepository
{
public:
    static OperationRepository* getInstance();
    std::shared_ptr<Operation> getOperationById(int idoperation);
    void insertOperation(Operation* operation);
    bool removeOperation(int idoperation);
    std::vector<std::shared_ptr<Operation>> getAllOperation();
    std::vector<std::shared_ptr<Operation>> getAllOperation(const QDate& date);
    std::vector<std::shared_ptr<Operation>> getAllOperation(int idteam);
    std::vector<std::shared_ptr<Operation>> getAllOperation(int idteam, const QDate& date);

    ~OperationRepository();
private:
    std::map<int, std::shared_ptr<Operation>> operationtable;
    static OperationRepository* instance;

    OperationRepository();
};

#endif // OPERATIONREPOSITORY_H
