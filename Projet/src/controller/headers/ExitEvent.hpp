#ifndef EXITEVENT_H
#define EXITEVENT_H

#include "DiaballikEvent.hpp"
#include "src/view/headers/View.hpp"

namespace dblk
{
class ExitEvent : public DiaballikEvent
{

  private:
    View & view_;

  public:
    ExitEvent(View & view);
    virtual void execute() override;

};

}


#endif // EXITEVENT_H
