#ifndef EVENTFACTORY_H
#define EVENTFACTORY_H

#include "DiaballikEvent.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/View/headers/View.hpp"

namespace dblk
{

class DiaballikEventFactory
{

  private:
    Diaballik & model_;
    View & view_;

  public:

    DiaballikEventFactory(Diaballik & model_, View & view_);

    DiaballikEvent * generateEvent(std::string input);

};

}


#endif // EVENTFACTORY_H
