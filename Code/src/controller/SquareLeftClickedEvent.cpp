#include "headers/SquareLeftClickedEvent.hpp"
#include "headers/MoveEvent.hpp"
#include "headers/SelectEvent.hpp"
#include "headers/PassEvent.hpp"

namespace dblk
{

SquareLeftClickedEvent::SquareLeftClickedEvent(Diaballik & model,
        View & view, int row, int col) :
    model_{model}, view_{view}, squarePos_{row, col} {}


void SquareLeftClickedEvent::execute()
{
    if (model_.getBoard().getPieceAt(squarePos_).has_value())
        SelectEvent(model_, view_, squarePos_).execute();
    else if (model_.getSelected().has_value())
        MoveEvent(model_, view_, squarePos_).execute();
    else
        view_.displayError("No piece has been selected to select an empty Square!");
}

}

