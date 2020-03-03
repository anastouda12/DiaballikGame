#include "src/model/headers/Diaballik.hpp"
#include "src/model/headers/Configs.hpp"

namespace dblk
{


//**********************************//
//* Implementation Classe Diaballik*//
//**********************************//


Diaballik::Diaballik(size_t size, bool variant):
    board_{size}, currentPlayer_{Team::NORTH}, winner_{nullptr}, selected_{}, moveCount_{DEFAULT_MOVES},
    canThrowBall_{true}
{
    board_.init(variant);
}

const Team & Diaballik::getCurrentPlayer() const
{
    return this->currentPlayer_;
}

unsigned Diaballik::getMoveCount() const
{
    return this->moveCount_;
}

const std::optional<Position> & Diaballik::getSelected() const
{
    return this->selected_;
}

const std::optional<Piece> & Diaballik::getPieceAt(const Position & position) const
{
    if (!this->board_.isInside(position)) throw std::invalid_argument("Out bounds!");
    else return this->board_.getPieceAt(position);
}


void Diaballik::passTurn()
{
    // Reset data game of currentPlayer
    this->currentPlayer_ = !this->currentPlayer_;
    this->selected_.reset();
    this->moveCount_ = DEFAULT_MOVES;
    this->canThrowBall_ = true;
    this->notifyObservers();
}


bool Diaballik::canPass() const
{
    return this->canThrowBall_;
}


int Diaballik::movePiece(const Position & pos)
{
    if (!this->selected_.has_value()) return -1; // select pos needed

    Position diff = pos - this->selected_.value();
    int steps = abs(diff.getRow()) + abs(
                         diff.getColumn());  // The number of moves done to achieve the final position
    if (steps > this->moveCount_) return -2;

    int flag = this->board_.movePiece(this->selected_.value(), pos);
    if (flag > 0)
    {
        this->moveCount_ -= steps;
        this->selected_.reset();
        this->notifyObservers();
        return steps;
    }
    return flag;
}


int Diaballik::throwBall(const Position & pos)
{
    if (!this->selected_.has_value()) return -1; // select pos needed
    else if (!this->canThrowBall_) return -2; //Cant pass
    else if (!this->board_.getPieceAt(this->selected_.value())->hasTheBall()) return -3; //No ball

    int flag{this->board_.passBall(this->currentPlayer_, this->selected_.value(), pos)};
    if (flag > 0)
    {
        this->canThrowBall_ = false;
        this->selected_.reset();
        this->notifyObservers();
        return 1;
    }
    return flag;
}

bool Diaballik::isOver()
{
    return this->board_.checksGameIsFinsh(this->winner_);
}


bool Diaballik::checksAntiGame()
{
    return this->board_.checksAntiGame(this->currentPlayer_);
}

int Diaballik::select(const Position & pos)
{
    if (this->board_.isFree(pos)) return -1; //No Piece
    if (!this->board_.isInside(pos)) return -2; //Out bounds
    if (this->board_.getPieceAt(pos)->getTeam() != this->currentPlayer_) return -3; //Opponent Piece

    this->selected_ = pos;
    this->notifyObservers();
    return 1;
}

unsigned Diaballik::getSizeBoard() const
{
    return this->board_.getSize();
}

Team * Diaballik::getWinner() const
{
    return this->winner_;
}

} // End namespace dblk
