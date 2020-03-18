#ifndef MOVEEVENT_HPP
#define MOVEEVENT_HPP

#include "DiaballikEvent.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/view/headers/View.hpp"

namespace dblk
{

class MoveEvent : public DiaballikEvent
{
  private:
    Diaballik & model_;
    View & view_;
    const Position endPos_;
  public:
    MoveEvent(Diaballik & model, View & view, const Position endPos);
    virtual void execute() override;
};

}

#endif // MOVEEVENT_HPP
