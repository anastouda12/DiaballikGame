#include "headers/PassEvent.hpp"


namespace dblk
{

/* PassEvent Class Implementation */

PassEvent::PassEvent(Diaballik & model, const Position endPos) : model_{model}, endPos_{endPos} {}

void PassEvent::execute()
{
    model_.throwBall(endPos_);
}

} //End namespace dblk
