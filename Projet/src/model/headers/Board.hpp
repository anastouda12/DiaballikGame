#ifndef _BOARD_H
#define _BOARD_H

#include "Piece.hpp"
#include "Position.hpp"
#include "Team.hpp"
#include <vector>
#include <optional>

namespace dblk
{

/**
 * @brief The Board class
 * This class represents the Board where the game will be played.
 * It will contain a vector of vectors containing the Pieces of the players.
 */
class Board
{

  private:
    /**
     * @brief pieces
     * The main container for the Pieces in the board.
     */
    std::vector<std::vector<std::optional<Piece>>> pieces_;

    /**
     * @brief size
     * The size of the board.
     */
    const unsigned size_;



  public:

    /**
    * @brief Board
    * Creates a new board with the given size.
    * No piece will be inside of the board.
    *
    * @param size The size of the board.
    */
    Board(const unsigned size);

    /**
     * @brief init
     * Puts the Pieces inside of the Board according the
     * Diaballik rules. The position of the initial pieces will
     * change according the variant rule.
     *
     * @param variant Is the variant rule applied or not.
     */
    void init(bool variant);

    /**
     * @brief getPieceAt
     * Retrieves the Piece at the given Position.
     *
     * @param position The position to retrieve the piece.
     * @return The piece at the given position, or nullptr if no piece.
     */
    const Piece * getPieceAt(Position position) const;

    /**
     * @brief isFree
     * Verifies if the position has a piece.
     *
     * @param pos The position to verify.
     * @return True if there is a piece.
     */
    bool isFree(Position pos) const;

    /**
     * @brief isFree
     * Verifies if the position is inside of the board.
     *
     * @param pos The position to verify.
     * @return True if is inside of the board.
     */
    bool isInside(Position pos) const;

    /**
     * @brief movePiece
     * Moves the Piece of the start Position to the end Position.
     * It is considered invalid to move to a already occuped position,
     * or out the bonds of the board.
     *
     * @param startPos The start Position of the Piece.
     * @param endPos The end Position of the Piece.
     * @return 1 if the Piece was moved or -1 in case of error.
     */
    int movePiece(Position startPos, Position endPos);


    /**
     * @brief checksAntiGame
     * Verifies if the given Player faces a situation of anti game.
     *
     * @param team The player to verify.
     * @return True in case of anti game situation.
     */
    bool checksAntiGame(Team team) const;

    /**
     * @brief checksGameIsFinsh
     * Verifies if the game is over.
     *
     * @return True if the game is over.
     */
    bool checksGameIsFinsh() const;

    /**
     * @brief passBall
     * Passes the ball between two pieces.
     * To pass the ball the end position must have a Piece from
     * the same color of the piece in the start Position, and must be
     * aligned without any opponent piece blocking the path.
     *
     * @param startPos The start position.
     * @param endPos The end position.
     * @return 1 if the ball has been passed or -1 if not.
     */
    int passBall(Position startPos, Position endPos);

    /**
     * @brief getWinner
     * Retrieves the winner of the game.
     *
     * @return The winner of the game, nullptr if the game isn't over.
     */
    const Team * getWinner() const;

  private:

    /**
     * @brief checkMove
     * Verifies if it's possible to move a Piece with
     * the given positions.
     *
     * @param startPos The start position.
     * @param endPos The end position.
     * @return True if it's allowed.
     */
    bool checkMove(Position startPos, Position endPos) const;

    /**
     * @brief checkThrow
     * Verifies if it's possible to pass a Piece with
     * the given positions.
     *
     * @param startPos The start position.
     * @param endPos The end position.
     * @return True if it's allowed.
     */
    bool checkThrow(Team color, Position startPos, Position endPos) const;

};

dblk::Position getMouvement(dblk::Position result);

}
#endif //_BOARD_H
