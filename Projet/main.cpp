#include <iostream>
#include "src/model/headers/Position.hpp"
#include "src/model/headers/Board.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/model/headers/Configs.hpp"
#include <vector>

using namespace std;

int main()
{

    dblk::Diaballik game{dblk::BIG_SIZE, true};
    cout << "\033[31m";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            optional<dblk::Piece> pc;
            try
            {
                pc = game.getPieceAt(dblk::Position(i, j));
                if (pc.has_value())
                {
                    cout << pc.value();
                }
                else
                {
                    cout << "( )";
                }
            }
            catch (std::invalid_argument & ex)
            {
                cout << ex.what() << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
