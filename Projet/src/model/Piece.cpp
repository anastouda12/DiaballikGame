#include "src/model/headers/Piece.hpp"

namespace dblk {

// ************************* //
// **Piece Implementation*** //
// ************************* //

Piece::Piece(const Team & team, const unsigned objectiveRow): team_{team}, haveBall_{false}, objectiveRow_{objectiveRow}  {}

bool Piece::hasTheBall() const{
    return this->haveBall_;
}

unsigned Piece::getObjectiveRow(){
    return this->objectiveRow_;
}


void Piece::givesTheBall(){
    this->haveBall_ = true;
}

void Piece::removesTheBall(){
    this->haveBall_ = false;
}


const Team * Piece::getTeam() const {
    return &team_;
}


std::string Piece::to_string() const{

    using std::string, std::to_string;
    if(haveBall_){return string("(*"+dblk::to_string(this->team_)+"*)");}

    return string("( "+dblk::to_string(this->team_)+" )");
}

// Non member methods.

std::ostream & operator<<(std::ostream & out, const Piece & piece){
    out << piece.to_string();
    return out;
}

}
