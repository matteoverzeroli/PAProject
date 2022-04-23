class OperationRepository{
/*...*/
public:
	std::vector<std::shared_ptr<Operation>> getAllOperation();
	std::vector<std::shared_ptr<Operation>> getAllOperation(const QDate& date);
	std::vector<std::shared_ptr<Operation>> getAllOperation(int idteam);
	std::vector<std::shared_ptr<Operation>> getAllOperation(int idteam, const QDate& date);
}