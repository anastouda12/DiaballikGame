#ifndef SQUAREUI_HPP
#define SQUAREUI_HPP
#include <QLabel>
#include "src/model/headers/Piece.hpp"
#include "src/controller/headers/EventManager.hpp"

namespace dblk
{
class SquareUI : public QLabel
{
    Q_OBJECT
  private:

    static const char * southPlayerImg;
    static const char * northPlayerImg;
    static const char * southPlayerBallImg;
    static const char * northPlayerBallImg;


  public:
    SquareUI(const std::optional<dblk::Piece> & piece, int size);
    void refreshPiece(const std::optional<Piece> & piece);

  public slots:
    void squareClicked(int row, int col, DiaballikEventManager * evntManager);

  signals:
    void clicked();

  protected:
    void mousePressEvent(QMouseEvent * event);

};

}

#endif // SQUAREUI_HPP
