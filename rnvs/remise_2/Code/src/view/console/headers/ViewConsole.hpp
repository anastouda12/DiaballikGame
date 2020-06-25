#ifndef VIEWCONSOLE_HPP
#define VIEWCONSOLE_HPP

// #include <iostream>  // rnvs : comm
// #include "src/model/headers/Diaballik.hpp"   // rnvs
#include "src/view/headers/View.hpp"


namespace dblk
{

class ViewConsole : public View
{

  public:

    /**
    * @brief ViewConsole Constructor by default of viewConsole.
    *
    **/
    ViewConsole() = default;

    /**
     * @brief displayMainMenu
     *
     * Display the main menu of the Diaballik game.
     *
     * @return the size of the game and variant.
     */
    virtual std::pair<size_t, bool> displayMainMenu() override;

    /**
     * @brief displayWelcomeMessage
     *
     * Displays a welcome message to the players
     */
    virtual void displayWelcomeMessage() override;

    /**
     * @brief displayBoard
     * Displays the boards of the Diaballik game
     */
    virtual void displayBoard(const Diaballik & diaballik) override;

    /**
     * @brief displayHelp
     * Displays the Help
     */
    virtual void displayHelp() override;

    /**
     * @brief displayCurrentPlayer
     *
     * Displays the current player of a game of Diaballik
     *
     * @param the team of the current player
     */
    virtual void displayCurrentPlayer(const Team & team) override;

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
    virtual void displayWinner(const std::optional<Team> & winner) override;

    /**
     * @brief displayError
     *
     * Display an error message
     *
     * @param errorMsg the message of error
     */
    virtual void displayError(std::string errorMsg) override;

    /**
     * @brief displayGoodByeMessage
     *
     * Display farewell message
     */
    virtual void displayGoodByeMessage() override;

    /**
     * @brief displaySelected
     *
     * Display if there is a Piece inside the position selected
     *
     * @param piece The optional piece selected
     */
    virtual void displaySelected(const std::optional<Piece> piece) override;


    /**
     * @brief askCommand
     *
     * Keyboard reading
     *
     * @return the command executed by the user
     */
    virtual std::string askCommand() override;

    /**
     * @brief displayLeftPlayer
     *
     * Displays a message to telling that a player left the game.
     *
     * @param team The player who left the game.
     */
    virtual void displayLeftPlayer(Team team) override;

    /**
     * @brief update update the view.
     *
     * @param obj the observable.
     */
    virtual void update(const Observable * obj) override;

};

} // End namespace dblk

#endif // VIEWCONSOLE_HPP
