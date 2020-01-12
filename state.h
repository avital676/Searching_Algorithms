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
    state(T state, double cost){
        cost = cost;
        Mystate = state;
        cameFrom = nullptr;
    }
    bool equals(state<T> s){
        return Mystate.equals(s.getMyState());

    }
    double getCost(){
        return cost;
    }
    state<T>* getCameFrom(){
        return cameFrom;
    }
    void setCameFrom(state<T> *s){
        this->cameFrom = s;
    }
    T getMyState(){
        return Mystate;
    }

};


#endif //EX4_STATE_H
