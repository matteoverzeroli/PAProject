#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginform/loginform.h"
#include <QQuickItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_team->hide();
    ui->formWidget_team->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inizializeMainWindowsUi(std::shared_ptr<User> user)
{
    user->initializeMainWindow(ui);
}
