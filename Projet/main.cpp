#include <iostream>
#include "src/model/headers/Position.hpp"
#include "src/model/headers/Board.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/View/Console/headers/ViewConsole.hpp"
#include "src/model/headers/Configs.hpp"
#include "src/controller/headers/MoveEvent.hpp"
#include "src/controller/headers/PassEvent.hpp"
#include "src/controller/headers/SelectEvent.hpp"
#include "src/controller/headers/DiaballikEvent.hpp"
#include "src/controller/headers/EventFactory.hpp"
#include <vector>

using namespace std;
using namespace dblk;


int main()
{
    Diaballik game(9, false);
    ViewConsole view;
    view.displayWelcomeMessage();
    view.update(&game);
    game.registerObserver(static_cast<Observer *>(&view));
    DiaballikEventFactory evnFactory{game, view};
    while (!game.isOver())
        try
        {
            DiaballikEvent * evn{ evnFactory.generateEvent(view.askCommand())};
            evn->execute();
            delete evn;
            if (game.getMoveCount() == 0 && !game.canPass()) game.passTurn();
        }
        catch (invalid_argument ex)
        {
            cout << endl << ex.what() << endl;
        }
        catch (runtime_error ex)
        {
            cout << ex.what() << endl;
        }
    cout << "Winner: " << *game.getWinner();

}

