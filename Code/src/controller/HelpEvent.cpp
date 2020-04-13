#include "headers/HelpEvent.hpp"

namespace dblk
{


HelpEvent::HelpEvent(View & view): view_{view} {}

void HelpEvent::execute()
{
    view_.displayHelp();
}


} //End Namespace dblk