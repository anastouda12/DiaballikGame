#include "headers/SquareUI.hpp"
#include "src/model/headers/Position.hpp"
#include <QPixmap>
#include <QVariant>
#include <QMouseEvent>
namespace dblk
{

const char *
SquareUI::southPlayerImg(":/resources/assets/southPlayer.png");
const char *
SquareUI::northPlayerImg(":/resources/assets/northPlayer.png");
const char *
SquareUI::southPlayerBallImg(":/resources/assets/southPlayerBall.png");
const char *
SquareUI::northPlayerBallImg(":/resources/assets/northPlayerBall.png");

SquareUI::SquareUI(Position & squarePos,
                   DiaballikEventManager * evnManager, int size) :
    squarePos_{squarePos}, evnManager_{evnManager}
{
    this->setProperty("class", "SquareUI");
    this->setFixedSize(size, size);
    this->setScaledContents(true);
}

void SquareUI::refreshPiece(const std::optional<Piece> & piece)
{
    clear();
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
}

void SquareUI::mousePressEvent(QMouseEvent * event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        emit leftClicked();
    }
    if (event->buttons() == Qt::RightButton)
    {
        emit rightClicked();
    }
}

void SquareUI::squareLeftClicked()
{
    evnManager_->executeEvent(EventType::SQUARE_LEFT_CLICKED,
                              squarePos_.getRow(), squarePos_.getColumn());
}

void SquareUI::squareRightClicked()
{
    evnManager_->executeEvent(EventType::SQUARE_RIGHT_CLICKED,
                              squarePos_.getRow(), squarePos_.getColumn());
}

}
