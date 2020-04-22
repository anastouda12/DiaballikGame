#ifndef BOARDUI_HPP
#define BOARDUI_HPP
#include <QGridLayout>
#include "src/model/headers/Board.hpp"
#include "SquareUI.hpp"



namespace dblk
{

class BoardUI : public QGridLayout
{

    std::vector<std::vector<SquareUI *>> squares_;
  public:
    BoardUI(const dblk::Board & board,
            DiaballikEventManager * evnManager);
    void refreshBoard(const Board & board);

};


}

#endif // BOARDUI_HPP
