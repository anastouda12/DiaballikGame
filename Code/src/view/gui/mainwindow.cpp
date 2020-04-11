#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800, 600));
    setStyleSheet("MainWindow {background:url(:/resources/images/background.jpg);}");
    ui->movesAvailableNumber->setPalette(QColor("#ff9100"));
    ui->throwAvailableNumber->setPalette(QColor("#ff9100"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnWelcome_exit_clicked()
{
    close();
}

void MainWindow::on_btnWelcome_play_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnWelcome_showRules_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_btnRules_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnGameOptions_mainMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnGameOptions_play_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_btnGamePage_leave_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnGamePage_passTurn_clicked()
{
    // PASSTURN game
}

void MainWindow::on_btnWinnerPage_exit_clicked()
{
    close();
}

void MainWindow::on_btnWinnerPage_mainMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
