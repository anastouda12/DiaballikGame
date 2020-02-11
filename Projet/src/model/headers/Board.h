/**
 * Project Untitled
 */


#ifndef _BOARD_H
#define _BOARD_H

#include "Piece.h"


class Board {
public: 
    Piece 10..18;
    
/**
 * @param size
 */
void Board(Integer size);
    
/**
 * @param variante
 */
void init(Boolean variante);
    
/**
 * @param position
 */
void getSupportAt(Position position);
    
/**
 * # Description
 * 
 * Retourne la taille du tableau.
 * @param pos
 */
void isFree(Position pos);
    
/**
 * @param startPos
 * @param endPos
 */
void moveSupport(Position startPos, Position endPos);
    
void checksAntiGame();
    
void checksGameIsFinsh();
    
/**
 * @param startPos
 * @param endPos
 */
void passBall(Position startPos, Position endPos);
    
void getWinner();
private: 
    /**
 * # Description
 * 
 * Represente la taille du plateau.
 */
const Integer size;
    /**
 * # Description
 * 
 * Conteneur des supports du plateau.
 */
Vector of size*size Supports board;
    
/**
 * @param startPos
 * @param endPos
 */
void checkMove(Position startPos, Position endPos);
    
/**
 * @param color
 * @param startPos
 * @param endPos
 */
void checkThrow(Team color, Position startPos, Position endPos);
    
/**
 * @param team
 */
void getSupportWhithBall(Team team);
};

#endif //_BOARD_H