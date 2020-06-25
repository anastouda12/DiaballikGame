#include "headers/HelpEvent.hpp"

#include "../view/headers/View.hpp" // rnvs

namespace dblk
{


HelpEvent::HelpEvent(View & view): view_{view} {}

void HelpEvent::execute()
{
    view_.displayHelp();
}


} //End Namespace dblk
