#ifndef _DIABILIK_H
#define _DIABILIK_H

#include "Board.hpp"
#include "Team.hpp"
#include "Observable.hpp"

namespace dblk
{

/**
 * @brief The Diabilik class
 */
class Diaballik : public Observable
{

  private:
    /**
     * @brief board
     * The main container of the Board of the Game.
     */
    Board board_;

    /**
     * @brief currentPlayer
     * The player who must move or pass.
     */
    Team currentPlayer_;


    Team * winner_;

    /**
     * @brief selected
     * The selected Piece to move or pass.
     */
    std::optional<Position> selected_;

    /**
     * @brief moveCount
     * The remaining moves in the current round.
     */
    unsigned moveCount_;

    /**
     * @brief canPass
     * Indicates if it's allowed to pass the ball in
     * the current round.
     */
    bool canThrowBall_;

  public:
    /**
     * @brief Diabilik
     * Creates a new Diaballik game.
     *
     * @param size The size of the Board.
     * @param variant Indicates if the variant rule is applied.
     */
    Diaballik(size_t size, bool variant);

    /**
     * @brief getCurrentPlayer
     * Retrieves the current player.
     *
     * @return The current player.
     */
    const Team & getCurrentPlayer() const;

    const std::optional<Position> & getSelected() const;

    const std::optional<Piece> & getPieceAt(const Position & position) const;

    /**
     * @brief getMoveCount
     * Retrieves the number of available moves in the current round.
     *
     * @return The number of available moves.
     */
    unsigned getMoveCount() const;

    /**
     * @brief passTurn
     * Swaps the current player for his opponent, and reset the available moves.
     */
    void passTurn();

    /**
     * @brief canPass
     * Verifies if the current player can pass his ball.
     *
     * @return True if he can pass his ball.
     */
    bool canPass() const;

    /**
     * @brief moveSupport
     * Moves the selected Piece to the given position.
     * The number of steps to achieve the final position
     * must not depass the number of available moves, and
     * if the piece has been moves it must refresh the available moves attribute.
     *
     * @param pos The position to move the piece.
     * @return The number of steps to achieve the position, or -1 if the piece
     * has not been moved.
     */
    int movePiece(const Position & pos);


    /**
     * @brief throwBall
     * If the selected piece has the ball, pass the ball to the given position.
     *
     * @param pos The position to pass the ball.
     * @return 1 if the ball has been passed, if not -1.
     */
    int throwBall(const Position & pos);

    /**
     * @brief isOver
     * Verifies if the game is over.
     *
     * @return True if the game is over, false if not.
     */
    bool isOver();

    /**
     * @brief checksAntiGame
     * Verifies if the current player is in a situation of anti-game.
     *
     * @return True if the current player faces a situation of anti-game.
     */
    bool checksAntiGame();

    /**
     * @brief select
     * Selects a piece in the given position. To select the piece, in the board the
     * given position must contain a Piece of the same color of the current player.
     *
     * @param pos The position to select the Piece.
     * @return 1 if a piece has been selected, -1 if not.
     */
    int select(const Position & pos);

    /**
     * @brief getSizeBoard
     * Gives the size of the board of the game Diaballik
     * @return the size of the board
     */
    unsigned getSizeBoard() const;

    /**
     * @brief getWinner
     * Gives the winner of the game diaballik
     * @return the winner Diaballik
     */
    Team * getWinner() const;


}; //End diaballik class

} //End namespace dblk

#endif //_DIABILIK_H
