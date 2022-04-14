#include "operationrepository.h"

OperationRepository* OperationRepository::instance = 0;

OperationRepository *OperationRepository::getInstance()
{
    if(instance == 0){
        instance = new OperationRepository();
    }
    return instance;
}

std::shared_ptr<Operation> OperationRepository::getOperationById(int idoperation)
{
    auto it = operationtable.find(idoperation);
    if(it != operationtable.end()){
        return it->second;
    }
    else{
        return std::shared_ptr<Operation>(nullptr);
    }
}

void OperationRepository::insertOperation(Operation *operation)
{
    std::shared_ptr<Operation> new_operation(operation);
    operationtable[operation->getIdoperation()] = new_operation;
}

bool OperationRepository::removeOperation(int idoperation)
{
    return operationtable.erase(idoperation);
}

OperationRepository::OperationRepository()
{

}
