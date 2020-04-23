#include "headers/SquareRightClickedEvent.hpp"
#include "headers/MoveEvent.hpp"
#include "headers/SelectEvent.hpp"
#include "headers/PassEvent.hpp"

namespace dblk
{

SquareRightClickedEvent::SquareRightClickedEvent(Diaballik & model,
        View & view, int row, int col) :
    model_{model}, view_{view}, squarePos_{row, col} {}


void SquareRightClickedEvent::execute()
{
    if (model_.getBoard().getPieceAt(squarePos_).has_value())
    {
        if (model_.getBoard().getPieceAt(
                    *model_.getSelected()).value().hasTheBall())
        {
            PassEvent(model_, view_, squarePos_).execute();
        }
        else
        {
            view_.displayError("Impossible to pass the ball from a piece without the ball");
        }
    }
    else
    {
        view_.displayError("No piece has been selected to select an empty Square!");
    }
}

}

