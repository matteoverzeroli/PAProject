#include "operationrepository.h"
#include "helpers.h"

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

std::vector<std::shared_ptr<Operation> > OperationRepository::getAllOperation()
{
    return Helpers::extract_values_from_map(operationtable);
}

std::vector<std::shared_ptr<Operation> > OperationRepository::getAllOperation(const QDate &date)
{
    auto operations = OperationRepository::getAllOperation();

    std::vector<std::shared_ptr<Operation>> result;

    for(auto it = operations.begin(); it != operations.end(); ++it){
        if((*it)->getStarttime()->date() == date){
            result.push_back((*it));
        }
    }
    return result;
}

std::vector<std::shared_ptr<Operation> > OperationRepository::getAllOperation(int idteam)
{
    auto operations = getAllOperation();
    std::vector<std::shared_ptr<Operation>> result;

    for(auto it = operations.begin(); it != operations.end(); ++it){
        if((*it)->getTeam()->getIdteam() == idteam){
            result.push_back((*it));
        }
    }
    return result;
}

std::vector<std::shared_ptr<Operation> > OperationRepository::getAllOperation(int idteam, const QDate &date)
{
   auto operations = OperationRepository::getAllOperation(idteam);

   std::vector<std::shared_ptr<Operation>> result;

   for(auto it = operations.begin(); it != operations.end(); ++it){
       if((*it)->getStarttime()->date() == date){
           result.push_back((*it));
       }
   }
   return result;
}

OperationRepository::OperationRepository()
{

}
