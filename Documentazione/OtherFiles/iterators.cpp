/** OperationRepository.cpp **/

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