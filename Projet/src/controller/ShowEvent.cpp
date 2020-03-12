#include "headers/ShowEvent.hpp"

namespace dblk
{

ShowEvent::ShowEvent(View & view, const Diaballik & model): view_{view}, model_{model} {}

void ShowEvent::execute()
{
    view_.displayBoard(model_);
}

}
