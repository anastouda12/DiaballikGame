#ifndef HELPEVENT_HPP
#define HELPEVENT_HPP

#include "DiaballikEvent.hpp"
#include "src/view/headers/View.hpp"

namespace dblk
{

/**
 * @brief The HelpEvent class
 *
 * Uses the user interface to display help to the user.
 */
class HelpEvent : public DiaballikEvent
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
     * @brief HelpEvent
     *
     * Creates a new help event.
     *
     * @param view The user interface.
     */
    explicit HelpEvent(View & view);

    /**
     * @brief execute
     *
     * Uses the user interface to display help
     * about how to use the app to the user.
     */
    virtual void execute() override;
};

}

#endif // HELPEVENT_HPP
