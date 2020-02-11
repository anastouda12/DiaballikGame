/**
 * Project Untitled
 */


#ifndef _DIABILIK_H
#define _DIABILIK_H

#include "Board.h"


class Diabilik {
public: 
    Board 1;
    
/**
 * @param size
 * @param variant
 */
void Diabilik(Integer size, Boolean variant);
    
/**
 * # Description
 * 
 * Retourne le gagnant de la partie.
 */
void getWinner();
    
void getMoveCount();
    
/**
 * # Description
 * 
 * Alterne entre le joueur courant.
 * Reset les moves du joueur courant Player.resetMoves();
 */
void passTurn();
    
void canPass();
    
/**
 * # Description
 * 
 * Deplace le support selectionnée vers la direction donnée.
 * Doit diminuer le nombre de déplacements disponibles du joueur courrant avec applyMove().
 * @param pos
 */
void moveSupport(Position pos);
    
/**
 * # Description
 * 
 * Lance la balle si le support selectionne la contient.
 * @param pos
 */
void throwBall(Position pos);
    
/**
 * # Description
 * 
 * Retourne la couleur du joueur courant.
 */
void getCurrentPlayer();
    
void isOver();
    
void checksAntiGame();
    
/**
 * @param pos
 */
void select(Position pos);
private: 
    /**
 * # Description
 * 
 * Pointeur vers le joueur courant. Doit etre mis a jour dans la methode passTurn().
 */
Team currentPlayer;
    /**
 * # Description
 * 
 * Pointeur vers la position du support selectionnée. 
 * Doit etre null à chaque turn.
 */
Position selected;
    Boolean throwAvailable;
    Integer moveCount;
};

#endif //_DIABILIK_H