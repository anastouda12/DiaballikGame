#ifndef SQUARECLICKEDEVENT_H
#define SQUARECLICKEDEVENT_H

#include "DiaballikEvent.hpp"
#include "src/model/headers/Diaballik.hpp"
#include "src/view/headers/View.hpp"

namespace dblk
{


    /**
     * @brief The SquareClickedEvent class
     */
    class SquareClickedEvent : public DiaballikAbstractEvent
    {
        private:
            /**
             * @brief model_
             *
             * The game data.
             */
            Diaballik &model_;

            /**
             * @brief view_
             *
             * The game view.
             */
            View &view_;

            /**
             * @brief squarePos_
             *
             * The position of the square.
             */
            Position squarePos_;
        public:
            /**
             * @brief SquareClickedEvent
             * @param model the game data.
             * @param view the game view.
             * @param row row of the square clicked.
             * @param col column of the square clicked.
             */
            SquareClickedEvent(Diaballik &model, View &view, int row, int col);

            /**
             * @brief execute
             */
            void execute() override;
    };

}
#endif // SQUARECLICKEDEVENT_H
