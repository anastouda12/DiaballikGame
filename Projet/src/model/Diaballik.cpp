#include "src/model/headers/Diaballik.hpp"
#include "src/model/headers/Configs.hpp"

namespace dblk
{


//**********************************//
//* Implementation Classe Diaballik*//
//**********************************//


Diaballik::Diaballik(unsigned size, bool variant):
    board_{size}, currentPlayer_{Team::NORTH}, selected_{}, moveCount_{DEFAULT_MOVES},
    canThrowBall_{true}, gameIsOver_{false}, antiGame_{false}
{board_.init(variant);}


const Team & Diaballik::getWinner() const{
    return this->board_.getWinner();
}

const Team & Diaballik::getCurrentPlayer() const{
    return this->currentPlayer_;
}

unsigned Diaballik::getMoveCount() const{
    return this->moveCount_;
}

void Diaballik::passTurn(){
    // Reset data game of currentPlayer
    this->currentPlayer_ = !this->currentPlayer_;
    this->selected_.reset();
    this->moveCount_ = DEFAULT_MOVES;
    this->canThrowBall_ = true;
}

bool Diaballik::canPass() const{
    return this->canThrowBall_;
}

int Diaballik::movePiece(Position pos){
    if(!this->selected_.has_value()) return -1; // select pos needed
    Position diff = pos - this->selected_.value();
    int steps = abs(diff.getRow()) + abs(diff.getColumn()); // The number of moves done to achieve the final position
    if(static_cast<unsigned>(steps) > this->moveCount_) return -1;
    if(this->board_.movePiece(this->selected_.value(), pos)){
        this->moveCount_ -= static_cast<unsigned>(steps);
        this->selected_.reset();
        return steps;
    }
    return -1;
}

int Diaballik::throwBall(Position pos){
    if(!this->selected_.has_value()) return -1; // select pos needed
    if(this->canThrowBall_ && this->board_.getPieceAt(this->selected_.value())->hasTheBall()){
        if(this->board_.passBall(this->currentPlayer_, this->selected_.value(), pos)){
            this->canThrowBall_ = false;
            this->selected_.reset();
            return 1;
        }
    }
    return -1;
}

bool Diaballik::isOver(){
    this->gameIsOver_ = this->board_.checksGameIsFinsh(this->currentPlayer_);
    return this->gameIsOver_;
}


bool Diaballik::checksAntiGame(){
    this->antiGame_ = this->board_.checksAntiGame(this->currentPlayer_);
    return this->antiGame_;
}

int Diaballik::select(Position pos){
    if(this->board_.isFree(pos) || this->gameIsOver_|| this->antiGame_) return -1;
    if(this->board_.getPieceAt(pos)->getTeam() == this->currentPlayer_){
        this->selected_ = pos;
        return 1;
    }
    return -1;
}




} // End namespace dblk
