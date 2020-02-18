#include <iostream>
#include "src/model/headers/Position.hpp"
#include "src/model/headers/Board.hpp"

using namespace std;

int main()
{
    dblk::Position p(1, 2);
    dblk::Position p2(3, 4);
    cout << p - p2 << endl;
    return 0;
}
