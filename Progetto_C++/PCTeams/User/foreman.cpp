#include "foreman.h"

Foreman::Foreman(const QString &password, const QString &name, const QString &surname,
                 QDate *birthday, const QString &email, const QString &cellnumber, const QChar &sex, std::shared_ptr<Team> team) :
    User(password, name, surname, birthday, email, cellnumber, sex),
    Administrator(password, name, surname, birthday, email, cellnumber, sex),
    Volunteer(password, name, surname, birthday, email, cellnumber, sex, team)
{}

Foreman::Foreman()
{

}

void Foreman::initializeMainWindow(Ui::MainWindow *ui)
{
    Volunteer::initializeMainWindow(ui);
    ui->stackedWidget_info->setCurrentIndex(0);
}

void Foreman::populateComboBoxTeams(QComboBox* comboBox, bool isForeman)
{
    if(isForeman){
        Administrator::populateComboBoxTeams(comboBox, isForeman);
    }
    else{
        comboBox->addItem(QString::number(team->getIdteam()) + " " + team->getName());
    }
}
