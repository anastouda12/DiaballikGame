#include "headers/BoardUI.hpp"
#include "src/controller/headers/Configs.hpp"

namespace dblk
{
BoardUI::BoardUI(const Board & board)
{
    for (int row = 0; row < static_cast<int>(board.getSize()); row++)
    {
        for (int col = 0; col < static_cast<int>(board.getSize()); col++)
        {
            Position curPos{row, col};
            SquareUI * square;
            switch (board.getSize())
            {
                case SMALL_SIZE:
                    square = new SquareUI(board.getPieceAt(curPos), 80);
                    break;
                case MEDIUM_SIZE:
                    square = new SquareUI(board.getPieceAt(curPos), 60);
                    break;
                case BIG_SIZE:
                    square = new SquareUI(board.getPieceAt(curPos), 40);
                    break;

            }
            this->addWidget(square, row, col);
        }
    }
}
}
