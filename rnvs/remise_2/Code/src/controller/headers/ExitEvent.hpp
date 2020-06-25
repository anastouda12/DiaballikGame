#ifndef EXITEVENT_H
#define EXITEVENT_H

#include "DiaballikAbstractEvent.hpp"
// #include "src/view/headers/View.hpp"// rnvs

namespace dblk
{

class View; // rnvs
class Diaballik;        // rnvs

/**
 * @brief The ExitEvent class
 *
 * This event when executed quits the app.
 */
class ExitEvent : public DiaballikAbstractEvent
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
     * The game data.
     */
    Diaballik & model_;

  public:

    /**
     * @brief ExitEvent
     *
     * Creates a new ExitEvent.
     *
     * @param view The user interface to inform the user.
     * @param model The game data.
     */
    explicit ExitEvent(View & view, Diaballik & model);

    /**
     * @brief execute
     *
     * Quits the app and tells to the user.
     */
    virtual void execute() override;

};

}


#endif // EXITEVENT_H
