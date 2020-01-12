//
// Created by noa on 12/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

#include "Point.cpp"
template <typename T>
class state {
private:
    T Mystate;
    double cost;
    state<T> *cameFrom;
public:
    state(T state, double cost);
    bool equals(state<T> s);
    double getCost();
    state<T>* getCameFrom();
    void setCameFrom(state<T> *s);
    T getMyState();

};


#endif //EX4_STATE_H
