#include "src/controller/headers/DiaballikEvent.hpp"


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
