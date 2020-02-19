#include "src/model/headers/Team.hpp"

namespace dblk
{

// ************************* //
// **Team Implementation*** //
// ************************* //

// No member methods.

Team operator!(const Team & team)
{
    if (team == NORTH)
    {
        return SOUTH;
    }
    else
    {
        return NORTH;
    }
}


std::string to_string(const Team & team)
{
    if (team == NORTH)
    {
        return "N";
    }
    else
    {
        return "S";
    }

}


std::ostream & operator<<(std::ostream & out, const Team & team)
{
    out << to_string(team);
    return out;
}


}
