#ifndef SHOWEVENT_H
#define SHOWEVENT_H

#include "DiaballikEvent.hpp"
#include "src/view/headers/View.hpp"

namespace dblk
{

class ShowEvent : public DiaballikEvent
{

    View & view_;
    const Diaballik & model_;

  public:
    ShowEvent(View & view, const Diaballik & model_);
    virtual void execute() override;
};

}

#endif // SHOWEVENT_H
