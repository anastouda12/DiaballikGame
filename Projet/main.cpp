#include <iostream>
#include "src/model/headers/Position.hpp"
#include "src/model/headers/Board.hpp"

using namespace std;

int main()
{

    const dblk::Team tt = dblk::Team::NORTH;
    dblk::Piece mp(tt,20);
    dblk::Piece xp(tt,20);
    xp.givesTheBall();
    cout << mp << endl;
    cout << xp << endl;
    return 0;
}
