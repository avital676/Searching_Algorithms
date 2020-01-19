#ifndef EX4_STATE_H
#define EX4_STATE_H

#include "Point.cpp"
#include <iostream>
#include <cfloat>
using namespace std;

template <typename T>
class state {
private:
    T Mystate;
    double cost;
    state<T> *cameFrom;
    //use only in A* algorithem.
    double Fheuristics;
   // double trailCost;

public:
    double sum;
    double trailCost;
    //construstor
    state(T state, double cost1) {
        cost = cost1;
        Mystate = state;
        cameFrom = nullptr;
        trailCost = cost1;
        Fheuristics = (FLT_MAX);
    }

    //check if 2 states are equals
    bool equals(state<T> s) {
        return Mystate->equals(s.getMyState());
    }

    double getCost(){
        return cost;
    }

    state<T>* getCameFrom(){
        return cameFrom;
    }

    double getTrailCost() {
        return trailCost;
    }

    void setTrailCost(double t) {
        trailCost = t;
    }

    void setCameFrom(state<T> *s){
        this->cameFrom = s;
    }

    T getMyState(){
        return Mystate;
    }

    void setFheuristics(double f) {
        Fheuristics = f;
    }

    double getFheuristics(){
        return Fheuristics;
    }

    void addToTrailCost(double i){
        trailCost =cost +i;
    }
};

#endif //EX4_STATE_H
