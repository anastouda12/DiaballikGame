#ifndef SQUAREUI_HPP
#define SQUAREUI_HPP
#include <QLabel>
#include "src/model/headers/Piece.hpp"
#include "src/model/headers/Position.hpp"
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

    Position squarePos_;
    DiaballikEventManager * evnManager_;

  public:
    SquareUI(Position & squarePos, DiaballikEventManager * evnManager, int size);
    void refreshPiece(const std::optional<Piece> & piece);

  public slots:
    void squareClicked();

  signals:
    void clicked();

  protected:
    void mousePressEvent(QMouseEvent * event);

};

}

#endif // SQUAREUI_HPP
