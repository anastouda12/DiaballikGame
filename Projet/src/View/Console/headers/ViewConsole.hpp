#ifndef VIEWCONSOLE_HPP
#define VIEWCONSOLE_HPP

#include <iostream>
#include "src/model/headers/Diaballik.hpp"
#include "src/View/headers/View.hpp"


namespace dblk
{

class ViewConsole : public View
{

  public:

    ViewConsole() = default;

    /**
     * @brief displayWelcomeMessage
     * Displays a welcome message to the players
     */
    virtual void displayWelcomeMessage() override;

    /**
     * @brief displayBoard
     * Displays the boards of the Diaballik game
     */
    virtual void displayBoard(const Board & board, const std::optional<Position> selected) override;

    /**
     * @brief displayHelp
     * Displays the Help
     */
    virtual void displayHelp() override;

    /**
     * @brief displayCurrentPlayer
     * Displays the current player of a game of Diaballik
     */
    virtual void displayCurrentPlayer(const Team & team) override;

    /**
     * @brief displayCounters
     * Displays the counters of the current players
     * Counter of movements available
     * And possibility to pass the ball
     */
    virtual void displayCounters(unsigned moveCounter, bool canPass) override;


    /**
     * @brief displayWinner
     * Displays the winner of the game Diaballik
     */
    virtual void displayWinner(const Team * team) override;

    /**
     * @brief displayError
     * Display an error message
     */
    virtual void displayError(int typeError,int flagError) override;

    virtual void displayGoodByeMessage() override;


    /**
     * @brief askCommand
     * Keyboard reading
     * @return the command executed by the user
     */
    std::string askCommand();

    virtual void update(const Observable * obj) override;

};

} // End namespace dblk

#endif // VIEWCONSOLE_HPP
