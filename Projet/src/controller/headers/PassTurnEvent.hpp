#ifndef PASSTURNEVENT_H
#define PASSTURNEVENT_H

#include "DiaballikEvent.hpp"
#include "src/model/headers/Diaballik.hpp"

namespace dblk
{
class PassTurnEvent : public DiaballikEvent
{

  private:
    Diaballik & model_;

  public:
    PassTurnEvent(Diaballik & model);
    virtual void execute() override;
};

}

#endif // PASSTURNEVENT_H
