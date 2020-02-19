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
    if (!this->isInside(position)) throw std::exception();
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


bool Board::checksAntiGame(Team team) const
{
    bool verifyLineAntiGame(const Board * board, Position currentPos, unsigned blockCount, Team team);
    bool haveAntiGame = false;
    for (int i = 0; i < this->size_; i++)
    {
        Position pos(i, 0);
        if (!this->isFree(pos))
            if (this->getPieceAt(pos)->getTeam() != team)
            {
                haveAntiGame = haveAntiGame || verifyLineAntiGame(this, pos, 0, team);
            }
    }
    return haveAntiGame;
}


bool Board::checksGameIsFinsh(Team team) const
{
    bool achievedObjective(const Board *, const Position &);
    for (unsigned i = 0; i < this->size_; i++)
    {
        Position top(0, i), bottom(this->size_ - 1, i);
        if (achievedObjective(this, bottom))
            return true;
        else if (achievedObjective(this, top))
            return false;
    }
    return checksAntiGame(team);
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

const Team & Board::getWinner() const
{
    bool achievedObjective(const Board *, const Position &);

    for (unsigned i = 0; i < this->size_; i++)
    {
        Position top(0, i), bottom(this->size_ - 1, i);
        if (achievedObjective(this, bottom))
            return this->getPieceAt(bottom)->getTeam();
        else if (achievedObjective(this, top))
            return this->getPieceAt(top)->getTeam();
    }
    throw std::exception();
}



//PRIVATE METHODS

bool Board::checkMove(Position startPos, Position endPos) const
{
    //The rules conditions for the startPos are verified when selecting the piece.
    if (!this->isInside(endPos)) return -1;        //Out bounds
    if (!this->isFree(endPos)) return -2;        //Occuped

    Position getDirection(Position result);
    Position direction = getDirection(startPos - endPos), currentPos(startPos + direction);
    while (currentPos != endPos)
    {
        if (!this->isFree(currentPos))
            return -3;      //Obstacle
        currentPos = currentPos + direction;
    }
    return 1;       //Is ok
}


int Board::checkThrow(Team team, Position startPos,
                      Position endPos) const
{
    //The rules conditions for the startPos are verified when selecting the piece.
    if (!this->isInside(endPos)) return -1;         //Out board bounds
    if (this->isFree(endPos)) return -2;        //No piece at end position.
    if (this->getPieceAt(endPos).value().getTeam() != team) return -3;      //Is opponent piece.

    Position getDirection(Position result);
    Position direction = getDirection(startPos - endPos), currentPos(startPos + direction);
    if (direction.getRow() == 0 && direction.getColumn() == 0) return -4;       //Not aligned
    while (currentPos != endPos)
    {
        if (!this->isFree(startPos))
            if (this->getPieceAt(startPos)->getTeam() != team)
                return -5;      //Obstacle
        currentPos = currentPos + direction;
    }
    return 1; //Is ok
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
        if (board->getPieceAt(position)->getObjectiveRow() == position.getRow() &&
                board->getPieceAt(position)->hasTheBall())
        {
            return true;
        }
    }
    return false;
}


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
    else
    {
        return Position(0, 0);
    }
}

/**
 * @brief verifyLineAntiGame
 * @param board
 * @param currentPos
 * @param blockCount
 * @param team
 * @return
 */
bool verifyLineAntiGame(const Board * board, Position currentPos, unsigned blockCount, Team team)
{

    void countBlockedOpponents(const Board * board, unsigned & blockCount, Position curentPos,
                               Team team);

    if (!board->isInside(currentPos) || board->isFree(currentPos))
    {
        return false;
    }
    else if (board->getPieceAt(currentPos)->getTeam() == team)
    {
        return false;
    }
    else
    {
        countBlockedOpponents(board, blockCount, currentPos, team);
        if ((unsigned)currentPos.getColumn() == board->getSize() - 1)
        {
            return blockCount >= 3;
        }
        else
        {
            return verifyLineAntiGame(board, Position(currentPos.getRow() - 1, currentPos.getColumn() + 1),
                                      blockCount, team) ||
                   verifyLineAntiGame(board, Position(currentPos.getRow(), currentPos.getColumn() + 1),
                                      blockCount, team) ||
                   verifyLineAntiGame(board, Position(currentPos.getRow() + 1, currentPos.getColumn() + 1),
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
void countBlockedOpponents(const Board * board, unsigned & blockCount, Position curentPos,
                           Team team)
{
    Position top(curentPos.getRow() - 1, curentPos.getColumn()),
             bottom(curentPos.getRow() + 1, curentPos.getColumn());
    if (board->isInside(top) && !board->isFree(top) &&
            board->getPieceAt(top)->getTeam() == team &&
            board->getPieceAt(top)->getObjectiveRow() == board->getSize() - 1)
    {
        blockCount++;
    }
    if (board->isInside(bottom) && !board->isFree(bottom) &&
            board->getPieceAt(bottom)->getTeam() == team &&
            board->getPieceAt(bottom)->getObjectiveRow() == 0)
    {
        blockCount++;
    }
}

} // End namespace dblk
