#ifndef SQUARERIGHTCLICKEDEVENT_HPP
#define SQUARERIGHTCLICKEDEVENT_HPP

#include "DiaballikEvent.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/view/headers/View.hpp"

namespace dblk
{


class SquareRightClickedEvent : public DiaballikAbstractEvent
{
  private:
    Diaballik & model_;
    View & view_;
    Position squarePos_;
  public:
    SquareRightClickedEvent(Diaballik & model, View & view, int row,
                            int col);
    void execute() override;
};

}

#endif // SQUARERIGHTCLICKEDEVENT_HPP
