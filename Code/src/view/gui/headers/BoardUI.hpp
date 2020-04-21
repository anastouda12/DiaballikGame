#ifndef BOARDUI_HPP
#define BOARDUI_HPP
#include <QGridLayout>
#include "src/model/headers/Board.hpp"
#include "SquareUI.hpp"



namespace dblk
{

class BoardUI : public QGridLayout
{
  public:
    BoardUI(const dblk::Board & board);

};

}

#endif // BOARDUI_HPP
