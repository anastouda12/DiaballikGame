#include <exception>
#include "headers/EventManager.hpp"
#include "headers/PassTurnEvent.hpp"
#include "headers/NewGameEvent.hpp"
#include "headers/SquareClickedEvent.hpp"

namespace dblk
{


//DiaballikEventFactory Implementation

DiaballikEventManager::DiaballikEventManager(Diaballik & model, View & view): model_{model}, view_{view} {}

void DiaballikEventManager::executeEvent(EventType type, int arg1, int arg2)
{
    switch (type)
    {
        case EventType::SQUARE_CLICKED:
            SquareClickedEvent(model_, view_, arg1, arg2).execute();
            break;
        case EventType::NEW_GAME:
            NewGameEvent(model_, arg1, arg2).execute();
            break;
        case EventType::PASS_TURN:
            PassTurnEvent(model_).execute();
            break;
        default:
            throw std::runtime_error("Unknown Event Type!");
    }
}


} // End namespace dblk
