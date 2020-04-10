#include "src/controller/headers/Controller.hpp"
#include "src/view/console/headers/ViewConsole.hpp"
#include "src/controller/headers/Configs.hpp"
#include "src/view/gui/headers/mainwindow.h"
#include <QApplication>



int main(int argc, char **argv)
{
    QApplication core(argc,argv);
    MainWindow main;
    main.show();
    return core.exec();

    dblk::ViewConsole view;
    std::pair<size_t, bool> initOptions {view.displayMainMenu()};
    dblk::Diaballik model{initOptions.first, initOptions.second};
    dblk::Controller controller{model, view};

    controller.init();
    controller.playGame();
}

