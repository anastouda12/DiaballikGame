/**
 * Project Untitled
 */


#ifndef _PIECE_H
#define _PIECE_H

class Piece {
public: 
    
/**
 * @param team
 */
void Piece(Team team);
    
void hasTheBall();
    
void givesTheBall();
    
void removesTheBall();
    
void getTeam();
    
void to_string();
    
void operator<<(out: & ostream)();
private: 
    Team team;
    boolean hasTheBall;
};

#endif //_PIECE_H