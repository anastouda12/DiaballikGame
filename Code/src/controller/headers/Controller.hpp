#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "src/view/headers/View.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "EventFactory.hpp"

namespace dblk
{

/**
 * @brief The Controller class
 *
 * This class assembles the different parts of the app.
 * It uses all the necessary data and algorithms to run the app.
 */
class Controller
{

  private:

    /**
     * @brief model_
     *
     * The main data of the game.
     */
    Diaballik & model_;

    /**
     * @brief view_
     *
     * The user interface.
     */
    View & view_;

    /**
     * @brief evntFactory_
     *
     * A factory of events launched by the user.
     */
    DiaballikEventFactory evntFactory_;

  public:

    /**
     * @brief Controller
     *
     * Creates a new app controller.
     *
     * @param model The game data.
     * @param view The UI.
     */
    Controller(Diaballik & model, View & view);

    /**
     * @brief init
     *
     * Associates the game data with the UI.
     */
    void init();

    /**
     * @brief playGame
     *
     * Contains the main algorithm of the game.
     */
    void playGame();

};


} // End namespace dblk

#endif // CONTROLLER_HPP
