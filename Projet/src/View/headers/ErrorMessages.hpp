#ifndef ERRORMESSAGES_HPP
#define ERRORMESSAGES_HPP

#include <vector>
#include <string>

namespace dblk
{

static std::vector<std::string> errorMessagesMove =
{
    "No position selected",
    "Not enough move available",
    "Out bound of the board",
    "Position already occupied",
    "Obstacle met",
    "Impossible to move the piece who has the ball"
};

static std::vector<std::string> errorMessageThrow =
{
    "No position selected",
    "Not possible to throw the ball",
    "No ball",
    "Out bound of the board",
    "No piece",
    "Piece of the opponent team",
    "Non aligned",
    "Obstacle met"
};

static std::vector<std::string> errorMessageSelect =
{
    "No piece",
    "Out bound of the board",
    "Piece of the opponent team"
};



} // end namespace dblk

#endif // ERRORMESSAGES_HPP
