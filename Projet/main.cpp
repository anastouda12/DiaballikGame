
#include "src/controller/headers/Controller.hpp"
#include "src/View/Console/headers/ViewConsole.hpp"
#include "src/model/headers/Configs.hpp"

int main()
{
    dblk::Diaballik model{dblk::MEDIUM_SIZE, false};
    dblk::ViewConsole view;
    dblk::Controller controller{model, view};

    controller.init();
    controller.playGame();

}

