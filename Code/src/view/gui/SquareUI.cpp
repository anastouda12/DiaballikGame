#include "headers/SquareUI.hpp"
#include <QPixmap>
#include <QVariant>
namespace dblk
{

const char * SquareUI::southPlayerImg(":/resources/assets/southPlayer.png");
const char * SquareUI::northPlayerImg(":/resources/assets/northPlayer.png");
const char * SquareUI::southPlayerBallImg(":/resources/assets/southPlayerBall.png");
const char * SquareUI::northPlayerBallImg(":/resources/assets/northPlayerBall.png");

SquareUI::SquareUI(const std::optional<Piece> & piece, int size)
{
    this->setProperty("class", "SquareUI");
    this->setFixedSize(size, size);
    this->setScaledContents(true);
    this->refreshPiece(piece);

}

void SquareUI::refreshPiece(const std::optional<Piece> & piece)
{
    if (piece)
    {
        QPixmap img;
        switch (piece->getTeam())
        {
            case NORTH:
                if (piece.value().hasTheBall())
                    img.load(northPlayerBallImg);
                else
                    img.load(northPlayerImg);
                break;
            case SOUTH:
                if (piece.value().hasTheBall())
                    img.load(southPlayerBallImg);
                else
                    img.load(southPlayerImg);
                break;
        }
        setPixmap(img);
    }
    else
    {
        clear();
    }
}

}
