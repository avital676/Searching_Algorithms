//
// Created by noa on 12/01/2020.
//

#include "state.h"

template<typename T>
state<T>::state(T state, double cost) {
    cost = cost;
    Mystate = state;
    cameFrom = nullptr;
}

template<typename T>
bool state<T>::equals(state<T> s) {
    return Mystate.equals(s.Mystate);
}

template<typename T>

double state<T>::getCost() {
    return cost;
}

template<typename T>
state<T>* state<T>::getCameFrom() {
    return cameFrom;
}

template<typename T>
void state<T>::setCameFrom(state<T> *s) {
    this->cameFrom = s;
}
template<typename T>
T state<T>::getMyState(){
    return Mystate;
}




