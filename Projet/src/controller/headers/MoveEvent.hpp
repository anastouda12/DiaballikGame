#ifndef MOVEEVENT_HPP
#define MOVEEVENT_HPP
#include "DiaballikEvent.hpp"
#include "../../model/headers/Diaballik.hpp"

namespace dblk
{


class MoveEvent : public DiaballikEvent
{
  private:
    Diaballik & model_;
    const Position endPos_;
  public:
    MoveEvent(Diaballik & model, const Position endPos);
    virtual void execute() override;
};

}

#endif // MOVEEVENT_HPP
