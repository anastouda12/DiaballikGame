#ifndef HELPEVENT_HPP
#define HELPEVENT_HPP

#include "DiaballikAbstractEvent.hpp"
// #include "src/view/headers/View.hpp" // rnvs

namespace dblk
{

class View; // rnvs

/**
 * @brief The HelpEvent class
 *
 * Uses the user interface to display help to the user.
 */
class HelpEvent : public DiaballikAbstractEvent
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
