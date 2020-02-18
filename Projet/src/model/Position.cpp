#include "headers/Position.hpp"

namespace dblk
{

//*************************//
//*Position Implementation*//
//*************************//

Position::Position(int row, int column) :
    row_{row}, column_{column} {}


int Position::getRow() const
{
    return this->row_;
}


int Position::getColumn() const
{
    return this->column_;
}


std::string Position::to_string() const
{
    using std::string, std::to_string;

    return string("( " + to_string(this->row_) + ", "
                  + to_string(this->column_) + " )");
}


Position Position::operator-(const Position & otherPos)
{
    return Position(this->row_ - otherPos.getRow(),
                    this->column_ - otherPos.column_);
}


Position Position::operator+(const Position & otherPos)
{
    return Position(this->row_ + otherPos.getRow(),
                    this->column_ + otherPos.column_);
}

// Nom member methods.

std::ostream & operator<<(std::ostream & out, const Position & pos)
{
    out << pos.to_string();
    return out;
}


}
