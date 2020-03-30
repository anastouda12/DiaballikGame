#ifndef DIABALLIKEVENT_H
#define DIABALLIKEVENT_H

#include "src/controller/headers/DiaballikAbstractEvent.hpp"

namespace dblk
{


/**
 * @brief The DiaballikEvent class
 *
 * Wrapper for an DiaballikAbstractEvent.
 */
class DiaballikEvent
{
  private:
    /**
     * @brief event_
     *
     * Pointer to a dynamic event that must be executed.
     */
    DiaballikAbstractEvent * event_;

  public:
    /**
     * @brief DiaballikEvent
     *
     * Creates a new DiaballikEvent.
     *
     * @param event The event that must be executed.
     */
    DiaballikEvent(DiaballikAbstractEvent * event);

    /**
     * @brief execute
     *
     * Executess the event.
     */
    void execute();

    ~DiaballikEvent();
};

}

#endif // DIABALLIKEVENT_H
