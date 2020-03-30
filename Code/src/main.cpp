#include "src/controller/headers/Controller.hpp"
#include "src/view/console/headers/ViewConsole.hpp"
#include "src/controller/headers/Configs.hpp"

int main()
{
    dblk::ViewConsole view;
    std::pair<size_t, bool> initOptions {view.displayMainMenu()};
    dblk::Diaballik model{initOptions.first, initOptions.second};
    dblk::Controller controller{model, view};

    controller.init();
    controller.playGame();
}

