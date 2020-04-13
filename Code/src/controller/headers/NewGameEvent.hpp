#ifndef NEWGAMEEVENT_H
#define NEWGAMEEVENT_H

#include "DiaballikEvent.hpp"

namespace dblk
{

class Diaballik;
class View;

/**
 * @brief The NewGameEvent class
 *
 * This event initializates the data of the game!
 */
class NewGameEvent : public DiaballikAbstractEvent
{

  private:
    /**
     * @brief model_
     *
     * The game data.
     */
    Diaballik & model_;

    int boardSize_;

    bool variant_;

  public:

    /**
     * @brief PassEvent
     *
     * Creates a new game event.
     *
     * @param model The game data.
     * @param view The UI.
     */
    NewGameEvent(Diaballik & model, int boardSize, bool variantMode);

    /**
     * @brief execute
     *
     * Initializates the game date accorting the given options.
     */
    virtual void execute() override;

};
}
#endif // NEWGAMEEVENT_H
