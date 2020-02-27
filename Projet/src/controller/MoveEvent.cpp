#include "headers/MoveEvent.hpp"

namespace dblk
{

MoveEvent::MoveEvent(Diaballik & model, const Position endPos) : model_{model}, endPos_{endPos} {}

void MoveEvent::execute()
{
    model_.movePiece(endPos_);
}

} //End namespace dblk
