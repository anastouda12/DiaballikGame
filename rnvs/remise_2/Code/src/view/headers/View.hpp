#ifndef VIEW_HPP
#define VIEW_HPP

// #include <iostream>  // rnvs : comm
// #include "src/model/headers/Diaballik.hpp"   // rnvs
// #include "src/view/headers/ErrorMessages.hpp"    // rnvs
#include "src/view/headers/Observer.hpp"

#include "src/model/headers/Team.hpp"   // rnvs : enum
#include <optional> // rnvs

namespace dblk
{

class Diaballik;    // rnvs
class Piece;    // rnvs

class View: public Observer
{

  public:

    /**
     * @brief displayMainMenu
     *
     * Display the main menu of the Diaballik game.
     *
     * @return the size of the game and variant.
     */
    virtual std::pair<size_t, bool> displayMainMenu() = 0;

    /**
     * @brief displayWelcomeMessage
     *
     * Displays a welcome message to the players
     */
    virtual void displayWelcomeMessage() = 0;

    /**
     * @brief displayBoard
     *
     * Displays the boards of the Diaballik game
     */
    virtual void displayBoard(const Diaballik & diaballik) = 0;

    /**
     * @brief displayHelp
     *
     * Displays the Help
     */
    virtual void displayHelp() = 0;

    /**
     * @brief displayCurrentPlayer
     *
     * Displays the current player of a game of Diaballik
     *
     * @param the team of the current player
     */
    virtual void displayCurrentPlayer(const Team & team) = 0;

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
    virtual void displayCounters(unsigned moveCounter, bool canPass) = 0;


    /**
     * @brief displayWinner
     *
     * Displays the winner of the game Diaballik
     *
     * @param team the optinal winner of the game Diaballik.
     */
    virtual void displayWinner(const std::optional<Team> & team) = 0;

    /**
     * @brief displayError
     *
     * Display an error message
     *
     * @param flagError flag of the error
     * @param typeError integer that represent the type error occured (select(1), move(2), pass(3))
     */
    virtual void displayError(std::string errorMsg) = 0;

    /**
     * @brief displayGoodByeMessage
     *
     * Display farewell message
     */
    virtual void displayGoodByeMessage() = 0;

    /**
     * @brief displaySelected
     *
     * Display if there is a Piece inside the position selected
     *
     * @param piece The optional piece selected
     */
    virtual void displaySelected(const std::optional<Piece> piece) = 0;

    /**
     * @brief askCommand
     *
     * Keyboard reading
     *
     * @return the command executed by the user
     */
    virtual std::string askCommand() = 0;

    /**
     * @brief displayLeftPlayer
     *
     * Displays a message to telling that a player left the game.
     *
     * @param team The player who left the game.
     */
    virtual void displayLeftPlayer(Team team) = 0;

}; //End class View

} // End namespace dblk


#endif // VIEW_HPP
