#include "headers/SelectEvent.hpp"


namespace dblk
{

SelectEvent::SelectEvent(Diaballik & model, const Position selectPos) : model_{model}, selectPos_{selectPos} {}

void SelectEvent::execute()
{
    model_.select(selectPos_);
}

} //End namespace dblk
