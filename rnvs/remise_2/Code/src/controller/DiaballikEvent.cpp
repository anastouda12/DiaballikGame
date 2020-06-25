#include "src/controller/headers/DiaballikEvent.hpp"

#include "../controller/headers/DiaballikAbstractEvent.hpp" // rnvs


namespace dblk
{

DiaballikEvent::DiaballikEvent(DiaballikAbstractEvent * event): event_{event} {}

void DiaballikEvent::execute()
{
    event_->execute();
}

DiaballikEvent::~DiaballikEvent()
{
    delete event_;
}

}
