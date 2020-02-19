#include "headers/Board.hpp"

namespace dblk
{


//******************************//
//* Implementation Classe Board*//
//******************************//

Board::Board(unsigned size) : size_{size}, pieces_{} {}

Piece::Piece(const Team & team, const unsigned objectiveRow): team_{team},
    haveBall_{false}, objectiveRow_{objectiveRow}  {}

void Board::init(bool variant)
{
    for (unsigned i = 0; i < this->size_; i++)
    {
        this->pieces_.push_back(std::vector<std::optional<Piece>>());
        for (unsigned j = 0; j < this->size_; j++)
        {
            if (i == 0)
            {
                this->pieces_[i].push_back(Piece(NORTH, this->size_ - 1));
            }
            else if (i == this->size_ - 1)
            {
                this->pieces_[i].push_back(Piece(SOUTH, 0));
            }
            else
            {
                this->pieces_[i].push_back(std::optional<Piece>());
            }
        }
    }
    if (variant)
    {
        this->pieces_[0].assign(
            1, Piece(SOUTH, this->size_ - 1));
        this->pieces_[0].assign(
            this->size_ - 2, Piece(SOUTH, this->size_ - 1));
        this->pieces_[this->size_ - 1].assign(
            1, Piece(NORTH, 0));
        this->pieces_[this->size_ - 1].assign(
            this->size_ - 2, Piece(NORTH, 0));
    }
}


const Piece * Board::getPieceAt(Position position) const
{
    if (this->pieces_[position.getRow()][position.getColumn()].has_value())
    {
        return &this->pieces_[position.getRow()][position.getColumn()].value();
    }
    else
    {
        return nullptr;
    }
}


bool Board::isFree(Position position) const
{
    return this->pieces_[position.getRow()][position.getColumn()].has_value();
}


bool Board::isInside(Position position) const
{
    return position.getRow() >= 0 && position.getRow() < this->size_;
}

int Board::movePiece(Position startPos, Position endPos)
{
    if (this->checkMove(startPos, endPos))
    {
        this->pieces_[startPos.getRow()][endPos.getColumn()].swap(
            this->pieces_[endPos.getRow()][endPos.getColumn()]);
    }
    return -1;
}

bool Board::checksAntiGame(Team team) const
{
    //TODO
    return false;
}

bool Board::checksGameIsFinsh() const
{
    //TODO
    return false;
}

bool passBall(Position startPos, Position endPos)
{
    //TODO
    return false;
}

const Team * Board::getWinner() const
{
    //See bottom of file.
    bool achievedObjective(const Board *, const Position &);

    for (unsigned i = 0; i < this->size_; i++)
    {
        Position top(0, i), bottom(this->size_ - 1, i);
        if (achievedObjective(this, bottom))
        {
            return this->getPieceAt(bottom)->getTeam();
        }
        else if (achievedObjective(this, top))
        {
            return this->getPieceAt(top)->getTeam();
        }
    }
    return nullptr;
}

bool Board::checkMove(Position startPos, Position endPos) const
{
    return this->isInside(endPos) && this->isFree(endPos) &&
           this->isInside(startPos) && !this->isFree(startPos);
}


//**********************************//
//* End Board Class Implementation *//
//**********************************//

//Utility Methods

/**
 * @brief achievedObjective
 * Verifies if the given position inside the board, contains a piece
 * who reached the objective with the ball.
 *
 * @param board The board of the game.
 * @param position The given position.
 * @return True if the board contains a piece who reached the objective.
 */
bool achievedObjective(const Board * board, const Position & position)
{
    if (!board->isFree(position))
    {
        if (board->getPieceAt(position)->getObjectiveRow() ==
                position.getRow() && board->getPieceAt(position)->hasTheBall())
        {
            return true;
        }
    }
    return false;
}

}
