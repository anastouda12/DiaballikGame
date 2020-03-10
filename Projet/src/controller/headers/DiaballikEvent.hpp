#ifndef DIABALLIKEVENT_H
#define DIABALLIKEVENT_H

namespace dblk
{

class DiaballikEvent
{
  public:
    virtual void execute() = 0;
    virtual ~DiaballikEvent() = default;
};

}

#endif // DIABALLIKEVENT_H
