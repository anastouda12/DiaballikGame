#ifndef SHOWEVENT_H
#define SHOWEVENT_H

#include "DiaballikAbstractEvent.hpp"
// #include "src/view/headers/View.hpp" // rnvs

namespace dblk
{

class View; // rnvs
class Diaballik;        // rnvs

/**
 * @brief The ShowEvent class
 *
 * This class is a passive event. It displays/refreshs the board.
 */
class ShowEvent : public DiaballikAbstractEvent
{

  private:
    /**
     * @brief view_
     *
     * The user interface.
     */
    View & view_;

    /**
    * @brief model_
    *
    * Read access to game data.
    */
    const Diaballik & model_;

  public:
    /**
     * @brief ShowEvent
     *
     * Creates a new show event.
     *
     * @param view The UI.
     * @param model_ Read acess to game data.
     */
    ShowEvent(View & view, const Diaballik & model);

    /**
     * @brief execute
     *
     * Displays or refresh the board in the screen.
     */
    virtual void execute() override;
};

} // End namespace dblk

#endif // SHOWEVENT_H
