#include "headers/PassTurnEvent.hpp"

#include "src/model/headers/Diaballik.hpp"  // rnvs

namespace dblk
{

PassTurnEvent::PassTurnEvent(Diaballik & model): model_{model} {}

void PassTurnEvent::execute()
{
    model_.passTurn();
}

} // End namespace dblk
