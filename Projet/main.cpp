#include <iostream>
#include "src/model/headers/Position.hpp"
#include "src/model/headers/Board.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/model/headers/Configs.hpp"
#include <vector>

using namespace std;

int main()
{

    dblk::Diaballik game{dblk::MEDIUM_SIZE, false};
    vector v1 = {1, 2, 3, 4, 5};
    cout << v1[20];
    return 0;
}
