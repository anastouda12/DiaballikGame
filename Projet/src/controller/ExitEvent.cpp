#include "headers/ExitEvent.hpp"

namespace dblk
{


ExitEvent::ExitEvent(View & view): view_{view} {}

void ExitEvent::execute()
{
    view_.displayGoodByeMessage();
    exit(2);
}


} // End namespace dblk
