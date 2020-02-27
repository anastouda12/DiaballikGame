#include <iostream>
#include "src/model/headers/Position.hpp"
#include "src/model/headers/Board.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/model/headers/Configs.hpp"
#include "src/controller/headers/MoveEvent.hpp"
#include "src/controller/headers/PassEvent.hpp"
#include "src/controller/headers/SelectEvent.hpp"
#include "src/controller/headers/DiaballikEvent.hpp"
#include <vector>

using namespace std;
using namespace dblk;

void displayBoard(const Diaballik & game)
{
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
}

vector<string> split(string s, string del)
{
    size_t pos = 0;
    std::string token;
    vector<string> result;
    while ((pos = s.find(del)) != std::string::npos)
    {
        token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + del.length());
    }
    result.push_back(s);
    return result;
}

inline DiaballikEvent * littleFac(Diaballik & game, vector<string> parser)
{
    if (parser[0] == string("move"))
    {
        return new MoveEvent(game, Position(stoi(parser[1]), stoi(parser[2])));
    }
    else     if (parser[0] == string("select"))
    {
        return new SelectEvent(game, Position(stoi(parser[1]), stoi(parser[2])));
    }
    else     if (parser[0] == string("pass"))
    {
        return new PassEvent(game, Position(stoi(parser[1]), stoi(parser[2])));
    }
}

int main()
{
    dblk::Diaballik game{dblk::BIG_SIZE, true};
    string cmd;
    vector<string> parser;
    displayBoard(game);
    while (true)
    {
        getline(cin, cmd);
        parser = split(cmd, string(" "));
        DiaballikEvent * evn{littleFac(game, parser)};
        evn->execute();
        displayBoard(game);
        if (!game.canPass() && game.getMoveCount() == 0)
        {
            game.passTurn();
        }
    }

    cout << "\033[31m";
    return 0;
}
