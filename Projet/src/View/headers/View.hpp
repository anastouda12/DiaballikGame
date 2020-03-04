#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream>
#include "src/model/headers/Diaballik.hpp"
#include "src/View/headers/Observer.hpp"


namespace dblk
{

class View: public Observer
{

  public:

    /**
     * @brief displayWelcomeMessage
     * Displays a welcome message to the players
     */
    virtual void displayWelcomeMessage() = 0;

    /**
     * @brief displayBoard
     * Displays the boards of the Diaballik game
     */
    virtual void displayBoard(const Board & board, const std::optional<Position>) = 0;

    /**
     * @brief displayHelp
     * Displays the Help
     */
    virtual void displayHelp() = 0;

    /**
     * @brief displayCurrentPlayer
     * Displays the current player of a game of Diaballik
     */
    virtual void displayCurrentPlayer(const Team & team) = 0;

    /**
     * @brief displayCounters
     * Displays the counters of the current players
     * Counter of movements available
     * And possibility to pass the ball
     */
    virtual void displayCounters(unsigned moveCounter, bool canPass) = 0;


    /**
     * @brief displayWinner
     * Displays the winner of the game Diaballik
     */
    virtual void displayWinner(const Team * team) = 0;

    /**
     * @brief displayError
     * Display an error message
     * @param errorMsg error message to display
     */
    virtual void displayError(std::string errorMsg) = 0;

    virtual void displayGoodByeMessage() = 0;

}; //End class View

} // End namespace dblk


#endif // VIEW_HPP
