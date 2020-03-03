#include <iostream>
#include "src/model/headers/Position.hpp"
#include "src/model/headers/Board.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/view/console/headers/View.hpp"
#include "src/model/headers/Configs.hpp"
#include <vector>

using namespace std;

int main()
{

   dblk::Diaballik dblke(7,false);
   dblk::View vd;
   vd.displayWelcomeMessage();

   vd.displayBoard(dblke);
   vd.displayCurrentPlayer(dblke.getCurrentPlayer());
   vd.displayCounters(dblke.getMoveCount(), dblke.canPass());
   vd.displayWinner(dblke.getWinner());
   vd.displayHelp();
    return 0;
}
