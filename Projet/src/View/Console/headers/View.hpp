#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream>
#include "src/model/headers/Diaballik.hpp"
#include "../../headers/Observer.hpp"

namespace dblk
{

class View : public Observer {

public:

    explicit View();

    /**
     * @brief displayWelcomeMessage
     * Displays a welcome message to the players
     */
    void displayWelcomeMessage();

    /**
     * @brief displayBoard
     * Displays the boards of the Diaballik game
     */
    void displayBoard(const Diaballik & game);

    /**
     * @brief displayHelp
     * Displays the Help
     */
    void displayHelp();

    /**
     * @brief displayCurrentPlayer
     * Displays the current player of a game of Diaballik
     */
    void displayCurrentPlayer(const Team & team);

    /**
     * @brief displayCounters
     * Displays the counters of the current players
     * Counter of movements available
     * And possibility to pass the ball
     */
    void displayCounters(unsigned moveCounter, bool canPass);


    /**
     * @brief displayWinner
     * Displays the winner of the game Diaballik
     */
    void displayWinner(const Team * team);

    /**
     * @brief displayError
     * Display an error message
     * @param errorMsg error message to display
     */
    void displayError(std::string errorMsg);


    /**
     * @brief askCommand
     * Keyboard reading
     * @return the command executed by the user
     */
    std::string askCommand();

    void update(const Observable *obj) override;
};

} // End namespace dblk

#endif // VIEW_HPP
