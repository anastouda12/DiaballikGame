#include "headers/Observable.hpp"

namespace dblk {


Observable::Observable(): observers_{} {}

void Observable::registerObserver(Observer * observer) {
    this->observers_.insert(observer);
}

void Observable::deleteObserver(Observer * observer) {
    this->observers_.erase(observer);
}

void Observable::notifyObservers() {
    for(Observer * obs : this->observers_) {
        obs->update(this);
    }
}

} // End namespace dblk
