#ifndef _PIECE_H
#define _PIECE_H

#include "Team.hpp"

namespace dblk
{

/**
 * @brief The Piece class
 */
class Piece
{

    /**
     * @brief team
     * The team owner of the piece.
     */
    Team team_;

    /**
     * @brief haveBall
     * Indicates if this piece has the ball.
     */
    bool haveBall_;

    /**
     * @brief objectiveRow
     * Indicates the objective row to win.
     * Usefull in the variant mode rule.
     */
    int objectiveRow_;

  public:

    /**
     * @brief Piece
     * Creates a new Piece.
     *
     * @param team The team owner of the Piece.
     */
    Piece(const Team & team, int objectiveRow);

    /**
     * @brief hasTheBall
     * Verifies if this piece has the ball.
     *
     * @return True if the piece has the ball.
     */
    bool hasTheBall() const;

    /**
     * @brief getObjectiveRow
     * Retrieve the objective row of the Piece.
     *
     * @return The objective row of the Piece.
     */
    int getObjectiveRow() const;

    /**
     * @brief givesTheBall
     * Gives the ball to the Piece.
     */
    void givesTheBall();

    /**
     * @brief removesTheBall
     * Removes the ball to the Piece.
     */
    void removesTheBall();

    /**
     * @brief getTeam
     * Retrieves the team owner of the Piece.
     *
     * @return The team owner of the Piece.
     */
    const Team & getTeam() const;

    /**
     * @brief to_string
     * Creates a string describing the Piece.
     *
     * @return A text description of the Piece.
     */
    std::string to_string() const;


};

/**
 * @brief operator <<
 * Allows to inject the Piece in the standard output.
 *
 * @param out An output stream.
 * @param piece The piece to inject.
 * @return The same output stream.
 */
std::ostream & operator<<(std::ostream & out,const Piece & piece);
}

#endif //_PIECE_HF
