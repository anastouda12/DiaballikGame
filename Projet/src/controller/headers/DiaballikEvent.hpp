#ifndef DIABALLIKEVENT_H
#define DIABALLIKEVENT_H

namespace dblk
{

/**
 * @brief The DiaballikEvent class
 *
 * This class represents a main action launched by the user.
 * It can be a passive action that dont modifies the game data (like ask for
 * help, refresh the board...) or
 * an active action who modifies the game data (move a piece, pass turn...).
 */
class DiaballikEvent
{
  public:
    /**
     * @brief execute
     *
     * Execute the event.
     */
    virtual void execute() = 0;

    virtual ~DiaballikEvent() = default;
};

}

#endif // DIABALLIKEVENT_H
