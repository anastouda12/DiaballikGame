#ifndef SQUARECLICKEDEVENT_H
#define SQUARECLICKEDEVENT_H

#include "DiaballikEvent.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/view/headers/View.hpp"

namespace dblk
{


class SquareClickedEvent : public DiaballikAbstractEvent
{
  private:
    Diaballik & model_;
    View & view_;
    Position squarePos_;
  public:
    SquareClickedEvent(Diaballik & model, View & view, int row, int col);
    void execute() override;
};

}
#endif // SQUARECLICKEDEVENT_H
