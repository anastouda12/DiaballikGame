#ifndef OBSERVER_HPP
#define OBSERVER_HPP

namespace dblk {

class Observable;


class Observer
{
public:

    Observer(const Observer &) = default;

    Observer(Observer &&) = default;

    Observer & operator=(const Observer &) = default;

    Observer & operator=(Observer &&) = default;

    virtual void update(const Observable * obj) = 0;

    virtual ~Observer() = default;

protected:
        Observer() = default;
};

}

#endif // OBSERVER_HPP
