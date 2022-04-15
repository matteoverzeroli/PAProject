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
    void on_pushButton_newuser_clicked();

    void on_pushButton_nu_adduser_clicked();

    void on_radioButton_nu_volunteer_toggled(bool checked);

    void on_radioButton_nu_foreman_toggled(bool checked);

    void on_actionLogout_triggered();

    void on_pushButton_showuser_clicked();

signals:
    void logout();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<User> currentuser;

};
#endif // MAINWINDOW_H
