#ifndef OPERATIONREPOSITORY_H
#define OPERATIONREPOSITORY_H

#include <memory>
#include <map>
#include <operation/operation.h>

class OperationRepository
{
public:
    static OperationRepository* getInstance();
    std::shared_ptr<Operation> getOperationById(int idoperation);
    void insertOperation(Operation* operation);
    bool removeOperation(int idoperation);

    ~OperationRepository();
private:
    std::map<int, std::shared_ptr<Operation>> operationtable;
    static OperationRepository* instance;

    OperationRepository();
};

#endif // OPERATIONREPOSITORY_H
