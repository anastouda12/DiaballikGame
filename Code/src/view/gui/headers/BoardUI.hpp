#ifndef BOARDUI_HPP
#define BOARDUI_HPP
#include <QGridLayout>
#include "src/model/headers/Diaballik.hpp"
#include "SquareUI.hpp"



namespace dblk
{

class BoardUI : public QGridLayout
{

    std::vector<std::vector<SquareUI *>> squares_;
  public:
    BoardUI(const dblk::Board & board, DiaballikEventManager * evnManager);
    void refreshBoard(const Diaballik & game);

  private:
    void refreshSquare(const Diaballik & game, SquareUI * square, Position & pos);

};


}

#endif // BOARDUI_HPP
