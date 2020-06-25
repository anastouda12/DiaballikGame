#include "headers/ShowEvent.hpp"

#include "src/view/headers/View.hpp"    // rnvs

namespace dblk
{

ShowEvent::ShowEvent(View & view, const Diaballik & model): view_{view}, model_{model} {}

void ShowEvent::execute()
{
    view_.displayBoard(model_);
}

}// End namespace dblk
