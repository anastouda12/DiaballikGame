#ifndef SELECTEVENT_HPP
#define SELECTEVENT_HPP

#include "DiaballikEvent.hpp"
#include "src/view/headers/View.hpp"
#include "src/model/headers/Diaballik.hpp"

namespace dblk
{
class SelectEvent : public DiaballikEvent
{

  private:
    Diaballik & model_;
    View & view_;
    const Position selectPos_;

  public:
    SelectEvent(Diaballik & model, View & view, const Position selectPos);
    virtual void execute() override;

};

}

#endif // SELECTEVENT_HPP
