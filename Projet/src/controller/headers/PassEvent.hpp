#ifndef PASSEVENT_H
#define PASSEVENT_H

#include "DiaballikEvent.hpp"
#include "src/model/headers/Diaballik.hpp"

namespace dblk
{

class PassEvent : public DiaballikEvent
{

  private:

    Diaballik & model_;
    const Position endPos_;

  public:
    PassEvent(Diaballik & model, const Position endPos);
    virtual void execute() override;

};

}

#endif // PASSEVENT_H
