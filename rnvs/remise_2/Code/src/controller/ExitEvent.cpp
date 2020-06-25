#include "headers/ExitEvent.hpp"

#include "../view/headers/View.hpp" // rnvs
#include "../model/headers/Diaballik.hpp"   // rnvs

namespace dblk
{


ExitEvent::ExitEvent(View & view, Diaballik & model): view_{view}, model_{model} {}

void ExitEvent::execute()
{
    view_.displayLeftPlayer(model_.getCurrentPlayer());
    view_.displayGoodByeMessage();
    exit(2);
}


} // End namespace dblk
