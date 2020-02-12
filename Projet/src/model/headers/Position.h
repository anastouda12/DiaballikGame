#ifndef _POSITION_H
#define _POSITION_H

#include <string>
#include <ostream>

namespace dblk
{

/**
 * @brief The Position class
 * This class will represent the coordinates to manipulate the board.
 */
class Position
{

  private:
    /**
     * @brief row
     * The row, so the index for the first vector in the Board.
     */
    const unsigned row;

    /**
     * @brief column
     * The column, so the index for the second vector in the Board.
     */
    const unsigned column;

  public:
    /**
     * @brief Position
     * Creates a new Position.
     *
     * @param row The row coordinate.
     * @param column The column coordinate.
     */
    Position(unsigned row, unsigned column);

    /**
     * @brief getRow
     * Retrieves the row of the position.
     *
     * @return The row of the position.
     */
    unsigned getRow() const;

    /**
     * @brief getColumn
     * Retrieves the row of the position.
     *
     * @return The row of the position.
     */
    unsigned getColumn() const;

    /**
     * @brief to_string
     * Creates a string describing the position in form of
     * ( row, column )
     *
     * @return A string describing the position.
     */
    std::string to_string();

    /**
     * @brief operator -
     * Subtrack 2 positions.
     *
     * @param otherPos The right operand.
     * @return The difference between the 2 Positons.
     */
    Position operator-(const Position & otherPos);

    /**
     * @brief operator +
     * Adds 2 positions.
     *
     * @param otherPos The right operand.
     * @return The sum between the 2 Positons.
     */
    Position operator+(const Position & otherPos);

};

/**
* @brief operator <<
* Allows to inject the Position in the standard output.
*
* @param out An output stream.
* @param pos The Position to inject.
* @return The same output stream.
*/
std::ostream operator<<(std::ostream & out, const Position & pos);

}

#endif //_POSITION_H
