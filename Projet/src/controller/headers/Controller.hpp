#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "src/View/headers/View.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "EventFactory.hpp"

namespace dblk
{

class Controller
{

  private:
    Diaballik & model_;
    View & view_;
    DiaballikEventFactory evntFactory_;

  public:
    Controller(Diaballik & model, View & view);

    void init();

    void playGame();

};


} // End namespace dblk

#endif // CONTROLLER_HPP
