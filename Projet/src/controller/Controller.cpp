#include "headers/Controller.hpp"

namespace dblk
{


Controller::Controller(Diaballik & model, View & view): model_{model}, view_{view}, evntFactory_{model, view} {}


void Controller::init()
{
    this->model_.registerObserver(&this->view_);
    this->view_.displayWelcomeMessage();
}

void Controller::playGame()
{
    this->view_.displayBoard(this->model_);
    while (!this->model_.isOver())
    {
        try
        {
            DiaballikEvent evn = this->evntFactory_.generateEvent(this->view_.askCommand());
            evn.execute();
        }
        catch (std::runtime_error & ex )
        {
            this->view_.displayError(ex.what());
        }
        catch (std::invalid_argument & ex )
        {
            this->view_.displayError(ex.what());
        }
    }
    this->view_.displayWinner(this->model_.getWinner());
    this->view_.displayGoodByeMessage();
}

} //End namespace dblk
