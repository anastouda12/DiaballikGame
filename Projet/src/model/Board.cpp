#include "headers/Board.hpp"
#include <exception>

namespace dblk
{


//******************************//
//* Implementation Classe Board*//
//******************************//


Board::Board(unsigned size) : size_{size},
    pieces_{size, std::vector<std::optional<Piece>>(size, std::optional<Piece>())} {}


void Board::init(bool variant)
{
    for (unsigned j = 0; j < this->size_; j++)
    {
        this->pieces_[0][j] = Piece(NORTH, this->size_ - 1);
        this->pieces_[this->size_ - 1][j] = Piece(SOUTH, 0);
    }
    this->pieces_[0][size_ / 2]->givesTheBall();
    this->pieces_[size_ - 1][size_ / 2]->givesTheBall();
    if (variant)
    {
        this->pieces_[0][1] = Piece(SOUTH, this->size_ - 1);
        this->pieces_[0][this->size_ - 2] = Piece(SOUTH, this->size_ - 1);
        this->pieces_[this->size_ - 1][1] = Piece(NORTH, 0);
        this->pieces_[this->size_ - 1][this->size_ - 2] = Piece(NORTH, 0);
    }
}

unsigned Board::getSize() const
{
    return this->size_;
}


const std::optional<Piece> & Board::getPieceAt(Position position) const
{
    return this->pieces_[position.getRow()][position.getColumn()];
}


bool Board::isFree(Position position) const
{
    return !this->getPieceAt(position).has_value();
}


bool Board::isInside(Position position) const
{
    return position.getRow() >= 0 && position.getRow() < (int)this->size_ &&
           position.getColumn() >= 0 && position.getRow() < (int)this->size_;
}


int Board::movePiece(Position startPos, Position endPos)
{
    int flag = this->checkMove(startPos, endPos);
    if (flag > 0)
    {
        this->pieces_[startPos.getRow()][endPos.getColumn()].swap(
            this->pieces_[endPos.getRow()][endPos.getColumn()]);
    }
    return flag;
}


//Verify if current player is victim of anti game.
bool Board::checksAntiGame(Team currentPlayer) const
{
    bool haveAntiGame = false;
    for (unsigned i = 0; i < this->size_; i++)
    {
        Position pos(i, 0);
        if (!this->isFree(pos))
            if (this->getPieceAt(pos)->getTeam() != currentPlayer)
            {
                haveAntiGame = haveAntiGame || verifyLineAntiGame(pos, 0, currentPlayer);
            }
    }
    return haveAntiGame;
}


bool Board::checksGameIsFinsh(Team * winner) const
{
    bool achievedObjective(const Board *, const Position &);
    for (unsigned i = 0; i < this->size_; i++)
    {
        Position top(0, i), bottom(this->size_ - 1, i);
        if (achievedObjective(this, bottom))
        {
            *winner = this->getPieceAt(bottom)->getTeam();
            return true;
        }
        else if (achievedObjective(this, top))
        {
            *winner = this->getPieceAt(top)->getTeam();
            return true;
        }
    }
    return false;
}


int Board::passBall(Team team, Position startPos, Position endPos)
{
    int flag = checkThrow(team, startPos, endPos);
    if (flag > 0)
    {
        this->pieces_[startPos.getRow()][startPos.getColumn()]->removesTheBall();
        this->pieces_[endPos.getRow()][endPos.getColumn()]->givesTheBall();
    }
    return flag;
}


//PRIVATE METHODS

int Board::checkMove(Position startPos, Position endPos) const
{
    //The rules conditions for the startPos are verified when selecting the piece.
    if (!this->isInside(endPos)) return -3;        //Out bounds(console)
    if (!this->isFree(endPos)) return -4;        //Occuped(console)

    Position getDirection(Position result);
    Position direction = getDirection(startPos - endPos), currentPos(startPos + direction);
    while (currentPos != endPos)
    {
        if (!this->isFree(currentPos))
            return -5;      //Obstacle
        currentPos = currentPos + direction;
    }
    return 1;       //Is ok
}


int Board::checkThrow(Team team, Position startPos,
                      Position endPos) const
{
    //The rules conditions for the startPos are verified when selecting the piece.
    if (!this->isInside(endPos)) return -4;         //Out board bounds
    if (this->isFree(endPos)) return -5;        //No piece at end position.
    if (this->getPieceAt(endPos).value().getTeam() != team) return -6;      //Is opponent piece.

    Position getDirection(Position result);
    Position direction = getDirection(startPos - endPos), currentPos(startPos + direction);
    if (direction.getRow() == 0 && direction.getColumn() == 0) return -7;       //Not aligned
    while (currentPos != endPos)
    {
        if (!this->isFree(startPos))
            if (this->getPieceAt(startPos)->getTeam() != team)
                return -8;      //Obstacle
        currentPos = currentPos + direction;
    }
    return 1; //Is ok
}

/**
 * @brief verifyLineAntiGame
 * @param board
 * @param currentPos
 * @param blockCount
 * @param team
 * @return
 */
bool Board::verifyLineAntiGame(Position currentPos, unsigned blockCount, Team team) const
{
    if (!this->isInside(currentPos) || this->isFree(currentPos))
    {
        return false;
    }
    else if (this->getPieceAt(currentPos)->getTeam() == team)
    {
        return false;
    }
    else if (checkLineBreak(currentPos, team))
    {
        return false;
    }
    else
    {
        countBlockedOpponents(blockCount, currentPos, team);
        if (currentPos.getColumn() == static_cast<int>(this->getSize() - 1))
        {
            return blockCount >= 3;
        }
        else
        {
            return verifyLineAntiGame(Position(currentPos.getRow() - 1, currentPos.getColumn() + 1),
                                      blockCount, team) ||
                   verifyLineAntiGame(Position(currentPos.getRow(), currentPos.getColumn() + 1),
                                      blockCount, team) ||
                   verifyLineAntiGame(Position(currentPos.getRow() + 1, currentPos.getColumn() + 1),
                                      blockCount, team);
        }
    }
}


/**
 * @brief countBlockedOpponents
 * Count the number of opponent pieces blocked by one piece. Used by verifyLineAntiGame.
 *
 * @param board The game board.
 * @param blockCount A reference to the number of opponent pieces blocked.
 * @param curentPos The current position.
 * @param team The victim of anti-game line.
 */
void Board::countBlockedOpponents(unsigned & blockCount, Position currentPos,
                                  Team team) const
{
    Position top(currentPos.getRow() - 1, currentPos.getColumn()),
             bottom(currentPos.getRow() + 1, currentPos.getColumn());
    if (this->isInside(top) && !this->isFree(top) &&
            this->getPieceAt(top)->getTeam() == team &&
            this->getPieceAt(top)->getObjectiveRow() == static_cast<int>(this->getSize() - 1))
    {
        blockCount++;
    }
    if (this->isInside(bottom) && !this->isFree(bottom) &&
            this->getPieceAt(bottom)->getTeam() == team &&
            this->getPieceAt(bottom)->getObjectiveRow() == 0)
    {
        blockCount++;
    }
}

bool Board::checkLineBreak(Position curentPos, Team team) const
{
    Position up(1, 0), down(-1, 0);
    Position top{curentPos + up}, bottom{curentPos + down};
    while (this->isInside(top))
    {
        if (!this->isFree(top) && this->getPieceAt(top)->getTeam() == team
                &&  this->getPieceAt(top)->getObjectiveRow() == 0)
        {
            return true;
        }
        top = top + up;
    }

    while (this->isInside(bottom))
    {
        if (!this->isFree(bottom) && this->getPieceAt(bottom)->getTeam() == team
                &&  this->getPieceAt(bottom)->getObjectiveRow() == this->getSize() - 1)
        {
            return true;
        }
        bottom = top + down;
    }
    return false;
}


//Utility Methods


/**
 * @brief getDirection
 * Returns a position representing the direction needed to achieve a piece
 * if they're aligned. If they re not aligned it returns the (0, 0) Position.
 *
 * @param result The difference of the start position and the end position.
 * @return The direction needed, or (0, 0) if they're not aligned.
 */
Position getDirection(Position result)
{
    //Horizontal alignement.
    if (result.getRow() == 0 )
    {
        if (result.getColumn() > 0) return Position(0, -1);
        else return Position(0, 1);
    }
    //Vertical allignement
    else if (result.getColumn() == 0)
    {
        if (result.getRow() > 0) return Position(-1, 0);
        else return Position(1, 0);
    }
    //Diagonal alignement
    else if (result.getRow() == result.getColumn())
    {
        if (result.getRow() < 0 && result.getColumn() < 0) return Position(1, 1);
        else if (result.getRow() < 0 && result.getColumn() > 0) return Position(1, -1);
        else if (result.getRow() > 0 && result.getColumn() > 0) return Position(-1, -1);
        else if (result.getRow() > 0 && result.getColumn() < 0) return Position(-1, 1);
    }
    //Not aligned.
    return Position(0, 0);
}


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
        if (board->getPieceAt(position)->getObjectiveRow() == position.getRow() &&
                board->getPieceAt(position)->hasTheBall())
        {
            return true;
        }
    }
    return false;
}


} // End namespace dblk
