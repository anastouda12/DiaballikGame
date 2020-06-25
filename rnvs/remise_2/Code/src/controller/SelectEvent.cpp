#include "headers/SelectEvent.hpp"
#include "src/view/headers/ErrorMessages.hpp"

#include "src/model/headers/Diaballik.hpp"  // rnvs
#include "src/view/headers/View.hpp"    // rnvs


namespace dblk
{


SelectEvent::SelectEvent(Diaballik & model, View & view, const Position selectPos) : model_{model},
    view_{view},
    selectPos_{selectPos} {}

void SelectEvent::execute()
{
    int flag = model_.select(selectPos_);
    if (flag < 0) this->view_.displayError(errorMessageSelect[abs(flag) - 1]);
}

} //End namespace dblk
