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
    for (unsigned j = 0; j < size_; j++)
    {
        pieces_[0][j] = Piece(NORTH, size_ - 1);
        pieces_[size_ - 1][j] = Piece(SOUTH, 0);
    }
    pieces_[0][size_ / 2]->givesTheBall();
    pieces_[size_ - 1][size_ / 2]->givesTheBall();
    if (variant)
    {
        pieces_[0][1] = Piece(SOUTH, size_ - 1);
        pieces_[0][size_ - 2] = Piece(SOUTH, size_ - 1);
        pieces_[size_ - 1][1] = Piece(NORTH, 0);
        pieces_[size_ - 1][size_ - 2] = Piece(NORTH, 0);
    }
}

unsigned Board::getSize() const
{
    return size_;
}


const std::optional<Piece> & Board::getPieceAt(const Position & position) const
{
    return pieces_[position.getRow()][position.getColumn()];
}


bool Board::isFree(const Position & position) const
{
    return !getPieceAt(position).has_value();
}


bool Board::isInside(const Position & position) const
{
    return position.getRow() >= 0 && position.getRow() < (int)size_ &&
           position.getColumn() >= 0 && position.getRow() < (int)size_;
}


int Board::movePiece(const Position & startPos, const Position & endPos)
{
    int flag = checkMove(startPos, endPos);
    if (flag > 0)
    {
        pieces_[startPos.getRow()][endPos.getColumn()].swap(
            pieces_[endPos.getRow()][endPos.getColumn()]);
    }
    return flag;
}


//Verify if current player is victim of anti game.
bool Board::checksAntiGame(Team currentPlayer) const
{
    bool haveAntiGame = false;
    for (unsigned i = 0; i < size_; i++)
    {
        Position pos(i, 0);
        if (!isFree(pos))
            if (getPieceAt(pos)->getTeam() != currentPlayer)
            {
                haveAntiGame = haveAntiGame || verifyLineAntiGame(pos, 0, currentPlayer);
            }
    }
    return haveAntiGame;
}


bool Board::checksGameIsFinsh(Team * winner) const
{
    bool achievedObjective(const Board *, const Position &);
    for (unsigned i = 0; i < size_; i++)
    {
        Position top(0, i), bottom(size_ - 1, i);
        if (achievedObjective(this, bottom))
        {
            *winner = getPieceAt(bottom)->getTeam();
            return true;
        }
        else if (achievedObjective(this, top))
        {
            *winner = getPieceAt(top)->getTeam();
            return true;
        }
    }
    return false;
}


int Board::passBall(Team team, const Position & startPos, const Position & endPos)
{
    int flag = checkThrow(team, startPos, endPos);
    if (flag > 0)
    {
        pieces_[startPos.getRow()][startPos.getColumn()]->removesTheBall();
        pieces_[endPos.getRow()][endPos.getColumn()]->givesTheBall();
    }
    return flag;
}


//PRIVATE METHODS

int Board::checkMove(const Position & startPos, const Position & endPos) const
{
    //The rules conditions for the startPos are verified when selecting the piece.
    if (!isInside(endPos)) return -3;        //Out bounds(console)
    if (!isFree(endPos)) return -4;        //Occuped(console)

    Position getDirection(Position result);
    Position direction = getDirection(startPos - endPos), currentPos(startPos + direction);
    while (currentPos != endPos)
    {
        if (!isFree(currentPos))
            return -5;      //Obstacle
        currentPos = currentPos + direction;
    }
    return 1;       //Is ok
}


int Board::checkThrow(Team team, const Position & startPos,
                      const Position & endPos) const
{
    //The rules conditions for the startPos are verified when selecting the piece.
    if (!isInside(endPos)) return -4;         //Out board bounds
    if (isFree(endPos)) return -5;        //No piece at end position.
    if (getPieceAt(endPos).value().getTeam() != team) return -6;      //Is opponent piece.

    Position getDirection(Position result);
    Position direction = getDirection(startPos - endPos), currentPos(startPos + direction);
    if (direction.getRow() == 0 && direction.getColumn() == 0) return -7;       //Not aligned
    while (currentPos != endPos)
    {
        if (!isFree(startPos))
            if (getPieceAt(startPos)->getTeam() != team)
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
bool Board::verifyLineAntiGame(const Position & currentPos, unsigned blockCount, Team team) const
{
    if (!isInside(currentPos) || isFree(currentPos))
    {
        return false;
    }
    else if (getPieceAt(currentPos)->getTeam() == team)
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
        if (currentPos.getColumn() == static_cast<int>(getSize() - 1))
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
void Board::countBlockedOpponents(unsigned & blockCount, const Position & currentPos,
                                  Team team) const
{
    Position top(currentPos.getRow() - 1, currentPos.getColumn()),
             bottom(currentPos.getRow() + 1, currentPos.getColumn());
    if (isInside(top) && !isFree(top) &&
            getPieceAt(top)->getTeam() == team &&
            getPieceAt(top)->getObjectiveRow() == static_cast<int>(getSize() - 1))
    {
        blockCount++;
    }
    if (isInside(bottom) && !isFree(bottom) &&
            getPieceAt(bottom)->getTeam() == team &&
            getPieceAt(bottom)->getObjectiveRow() == 0)
    {
        blockCount++;
    }
}

bool Board::checkLineBreak(const Position & curentPos, Team team) const
{
    Position up(1, 0), down(-1, 0);
    Position top{curentPos + up}, bottom{curentPos + down};
    while (isInside(top))
    {
        if (!isFree(top) && getPieceAt(top)->getTeam() == team
                &&  getPieceAt(top)->getObjectiveRow() == 0)
        {
            return true;
        }
        top = top + up;
    }

    while (isInside(bottom))
    {
        if (!isFree(bottom) && getPieceAt(bottom)->getTeam() == team
                &&  getPieceAt(bottom)->getObjectiveRow() == getSize() - 1)
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
