#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>
#include "src/View/headers/Observer.hpp"

namespace dblk
{


class Observable
{

  private:
    std::set<Observer *> observers_;

  public:
    Observable();

    void registerObserver(Observer * observer);

    void deleteObserver(Observer * observer);

    void notifyObservers();
};

}

#endif // OBSERVABLE_H
