#ifndef SELECTEVENT_HPP
#define SELECTEVENT_HPP

#include "DiaballikEvent.hpp"
#include "src/model/headers/Diaballik.hpp"

namespace dblk
{
class SelectEvent : public DiaballikEvent
{

  private:
    Diaballik & model_;
    const Position selectPos_;

  public:
    SelectEvent(Diaballik & model, const Position selectPos);
    virtual void execute() override;

};

}

#endif // SELECTEVENT_HPP
