#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_btnWelcome_exit_clicked();
    void on_btnWelcome_play_clicked();
    void on_btnWelcome_showRules_clicked();
    void on_btnRules_back_clicked();
    void on_btnGameOptions_mainMenu_clicked();
    void on_btnGameOptions_play_clicked();
    void on_btnGamePage_leave_clicked();
    void on_btnGamePage_passTurn_clicked();
    void on_btnWinnerPage_exit_clicked();
    void on_btnWinnerPage_mainMenu_clicked();
};

#endif // MAINWINDOW_H
