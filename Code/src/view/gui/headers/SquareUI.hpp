#ifndef SQUAREUI_HPP
#define SQUAREUI_HPP
#include <QLabel>
#include "src/model/headers/Piece.hpp"
#include "src/model/headers/Position.hpp"
#include "src/controller/headers/EventManager.hpp"

namespace dblk
{
    /**
     * @brief The SquareUI class
     */
    class SquareUI : public QLabel
    {
            Q_OBJECT
        private:
            /**
            * @brief southPlayerImg
            * Image of the south player.
            */
            static const char *southPlayerImg;
            /**
            * @brief northPlayerImg
            * Image of the north player.
            */
            static const char *northPlayerImg;
            /**
            * @brief southPlayerBallImg
            * Image of the south player with the ball.
            */
            static const char *southPlayerBallImg;
            /**
            * @brief northPlayerBallImg
            * Image of the north player with the ball.
            */
            static const char *northPlayerBallImg;

            /**
             * @brief squarePos_
             * Position of the square
             */
            Position squarePos_;

            /**
             * @brief evnManager_
             * Event manager.
             */
            DiaballikEventManager *evnManager_;

        public:
            /**
             * @brief SquareUI
             * SquareUI.
             * @param squarePos Square position.
             * @param evnManager Event Manager.
             * @param size The size.
             */
            SquareUI(Position &squarePos, DiaballikEventManager *evnManager, int size);

            /**
             * @brief refreshPiece
             * Refresh a piece.
             * @param piece The optional Piece.
             */
            void refreshPiece(const std::optional<Piece> &piece);

            /**
             * @brief setInterectable
             * Set a squareUI interectable in the board.
             */
            void setInterectable();

            /**
             * @brief setSelected
             * Set the square selected.
             */
            void setSelected();

            /**
             * @brief setDefaultBackground
             * Set default background.
             */
            void setDefaultBackground();

        public slots:
            /**
             * @brief squareClicked
             */
            void squareClicked();
            /**
             * @brief squareRightClicked
             */
            void squareRightClicked();
        signals:
            /**
             * @brief clicked
             */
            void clicked();
            /**
             * @brief rightClicked
             */
            void rightClicked();

        protected:
            /**
             * @brief mousePressEvent
             * @param event the mouse Event.
             */
            void mousePressEvent(QMouseEvent *event);

    };

}

#endif // SQUAREUI_HPP
