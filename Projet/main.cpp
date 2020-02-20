#include <iostream>
#include "src/model/headers/Position.hpp"
#include "src/model/headers/Board.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/model/headers/Configs.hpp"
#include <vector>

using namespace std;

int main()
{

    dblk::Diaballik game{dblk::MEDIUM_SIZE,false};
    cout << game.select({0,3}) << endl;
    cout << game.throwBall({0,2}) << endl;
    return 0;
}
