#include <iostream>
#include "src/model/headers/Position.hpp"
#include "src/model/headers/Board.hpp"
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(0);
    dblk::Position p(1, 2);
    dblk::Position p2(3, 4);
    cout << p - p2 << " et " << v1[0] << endl;
    int x = 0;
    const int * px = &x;
    dblk::Board b(9);
    return 0;
}
