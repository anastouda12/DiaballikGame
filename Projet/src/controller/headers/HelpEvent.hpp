#ifndef HELPEVENT_HPP
#define HELPEVENT_HPP

#include "DiaballikEvent.hpp"
#include "src/view/headers/View.hpp"

namespace dblk
{

class HelpEvent : public DiaballikEvent
{

    View & view_;

  public:
    HelpEvent(View & view);
    virtual void execute() override;
};

}

#endif // HELPEVENT_HPP
