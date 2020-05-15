#ifndef BOARDUI_HPP
#define BOARDUI_HPP
#include <QGridLayout>
#include "src/model/headers/Diaballik.hpp"
#include "SquareUI.hpp"



namespace dblk
{

/**
 * @brief The BoardUI class
 */
class BoardUI : public QGridLayout
{

    /**
     * @brief squares_
     */
    std::vector<std::vector<SquareUI *>> squares_;
  public:
    /**
     * @brief BoardUI
     * Creates a new board depending on the game data.
     *
     * @param board
     * @param evnManager
     */
    BoardUI(const dblk::Board & board, DiaballikEventManager * evnManager);
    /**
     * @brief refreshBoard
     * Refresh the board game.
     * @param game the game.
     */
    void refreshBoard(const Diaballik & game);

  private:
    /**
     * @brief refreshSquare
     * Refresh a square of the game board.
     * @param game the game data.
     * @param square the square to refresh.
     * @param pos Position of the square.
     */
    void refreshSquare(const Diaballik & game, SquareUI * square, Position & pos);

};


}

#endif // BOARDUI_HPP
