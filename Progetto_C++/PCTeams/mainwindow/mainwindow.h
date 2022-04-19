#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user/user.h"
#include <memory>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void inizializeMainWindowsUi(std::shared_ptr<User> user);

private slots:
    void on_pushButton_nu_adduser_clicked();

    void on_radioButton_nu_volunteer_toggled(bool checked);

    void on_radioButton_nu_foreman_toggled(bool checked);

    void on_actionLogout_triggered();

    void on_comboBox_du_team_currentTextChanged(const QString &arg1);

    void on_pushButton_du_deleteuser_clicked();

    void on_pushButton_op_add_clicked();

    void on_pushButton_op_newop_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_commandLinkButton_newuser_clicked();

    void on_commandLinkButton_operation_clicked();

    void on_commandLinkButton_deleteuser_clicked();

    void on_commandLinkButton_showusers_clicked();

    void on_commandLinkButton_home_clicked();

    void on_commandLinkButton_home_2_clicked();

    void on_commandLinkButton_home_3_clicked();

    void on_commandLinkButton_home_4_clicked();

signals:
    void logout();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<User> currentuser;

    bool nullNewUserAttribute();
    bool nullNewOperationAttribute();
    void clearNewUserAttribute();
    void clearNewOperationAttribute();

};
#endif // MAINWINDOW_H
