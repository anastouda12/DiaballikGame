#ifndef SQUAREUI_HPP
#define SQUAREUI_HPP
#include <QLabel>
#include "src/model/headers/Piece.hpp"

namespace dblk
{
class SquareUI : public QLabel
{
  private:

    static const char * southPlayerImg;
    static const char * northPlayerImg;
    static const char * southPlayerBallImg;
    static const char * northPlayerBallImg;


  public:
    SquareUI(const std::optional<dblk::Piece> & piece, int size);
    void refreshPiece(const std::optional<Piece> & piece);

};

}

#endif // SQUAREUI_HPP
