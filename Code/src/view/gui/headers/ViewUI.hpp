#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/view/headers/View.hpp"
#include "src/controller/headers/EventManager.hpp"
#include "src/model/headers/Diaballik.hpp"

namespace Ui
{
class MainWindow;
}

namespace dblk
{

class ViewUI : public QMainWindow, public View
{
    Q_OBJECT

  private:
    Ui::MainWindow * mainWindow_;
    dblk::DiaballikEventManager * evntManager_;

  public:
    explicit ViewUI(QWidget * parent = nullptr);

    void setEventManager(DiaballikEventManager * evntManager);

    /**
     * @brief displayCurrentPlayer
     *
     * Displays the current player of a game of Diaballik
     *
     * @param the team of the current player
     */
    virtual void displayCurrentPlayer(const dblk::Team & team)  override;


    /**
     * @brief displayCounters
     *
     * Displays the counters of the current players
     * Counter of movements available
     * And possibility to pass the ball
     *
     * @param moveCounter the number of moves availables of the current Player
     * @param canPass possibility to throw the ball of the current player
     */
    virtual void displayCounters(unsigned moveCounter, bool canPass) override;

    /**
     * @brief displayWinner
     *
     * Displays the winner of the game Diaballik
     *
     * @param team the optinal winner of the game Diaballik.
     */
    virtual void displayWinner(const std::optional<dblk::Team> & team)  override;

    /**
     * @brief displaySelected
     *
     * Display if there is a Piece inside the position selected
     *
     * @param piece The optional piece selected
     */
    virtual void displaySelected(const std::optional<dblk::Piece> piece)  override;

    /**
     * @brief displayBoard
     *
     * Displays the boards of the Diaballik game
     */
    virtual void displayBoard(const dblk::Diaballik & diaballik) override;


    virtual void update(const dblk::Observable * observable) override;

    ~ViewUI();

  public slots:

    /**
     * @brief displayHelp
     *
     * Displays the Help
     */
    virtual void displayHelp()  override;

    /**
     * @brief displayError
     *
     * Display an error message
     *
     * @param flagError flag of the error
     * @param typeError integer that represent the type error occured (select(1), move(2), pass(3))
     */
    virtual void displayError(std::string errorMsg)  override;

    /**
     * @brief displayGoodByeMessage
     *
     * Display farewell message
     */
    virtual void displayGoodByeMessage()  override;


    /**
     * @brief displayLeftPlayer
     *
     * Displays a message to telling that a player left the game.
     *
     * @param team The player who left the game.
     */
    virtual void displayLeftPlayer(dblk::Team team)  override;

    /**
     * @brief displayMainMenu
     *
     * Display the main menu of the Diaballik game.
     *
     * @return the size of the game and variant.
     */
    virtual void displayOptionsMenu() override;

    /**
     * @brief displayWelcomeMessage
     *
     * Displays a welcome message to the players
     */
    virtual void displayWelcomePage() override;


  private:
    void initSlots();

  private slots:
    void initGame();

};

}

#endif // MAINWINDOW_H
