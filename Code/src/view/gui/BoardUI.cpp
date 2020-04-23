#include "headers/BoardUI.hpp"
#include "src/controller/headers/Configs.hpp"

namespace dblk
{
BoardUI::BoardUI(const Board & board,
                 DiaballikEventManager * evnManager)
    : squares_(board.getSize(), std::vector<SquareUI *>(board.getSize(),
               nullptr))
{
    for (int row = 0; row < static_cast<int>(board.getSize()); row++)
    {
        for (int col = 0; col < static_cast<int>(board.getSize()); col++)
        {
            Position curPos{row, col};
            SquareUI * square = new SquareUI(curPos, evnManager,
                                             board.getSize() * 10 - 10);
            square->refreshPiece(board.getPieceAt(curPos));
            connect(square, &SquareUI::leftClicked, square,
                    &SquareUI::squareLeftClicked);
            connect(square, &SquareUI::rightClicked, square,
                    &SquareUI::squareRightClicked);
            squares_[row][col] = square;
            this->addWidget(square, row, col);
        }
    }
}


void BoardUI::refreshBoard(const Board & board)
{
    for (int row = 0; row < board.getSize(); row++)
    {
        for (int col = 0; col < board.getSize(); col++)
        {
            Position curPos{row, col};
            SquareUI * square = squares_[row][col];
            square->refreshPiece(board.getPieceAt(curPos));
        }
    }
}
}
