#ifndef EXITEVENT_H
#define EXITEVENT_H

#include "DiaballikEvent.hpp"
#include "src/view/headers/View.hpp"

namespace dblk
{
/**
 * @brief The ExitEvent class
 *
 * This event when executed quits the app.
 */
class ExitEvent : public DiaballikEvent
{

  private:

    /**
     * @brief view_
     *
     * The user interface.
     */
    View & view_;

  public:

    /**
     * @brief ExitEvent
     *
     * Creates a new ExitEvent.
     *
     * @param view The user interface to inform the user.
     */
    explicit ExitEvent(View & view);

    /**
     * @brief execute
     *
     * Quits the app and tells to the user.
     */
    virtual void execute() override;

};

}


#endif // EXITEVENT_H
