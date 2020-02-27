#include "headers/PassEvent.hpp"


namespace dblk
{

/* PassEvent Class Implementation */

PassEvent::PassEvent(Diaballik & model, const Position endPos) : model_{model}, endPos_{endPos} {}

void PassEvent::execute()
{
    int flag = model_.throwBall(endPos_);
    if (flag < 0)
    {
        //Error;
    }
}

} //End namespace dblk
