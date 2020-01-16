//
// Created by noa on 12/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H
using namespace std;
#include "Point.cpp"
#include <iostream>
#include <cfloat>
template <typename T>
class state {
private:
    T Mystate;
    double cost;
    state<T> *cameFrom;
    double Fheuristics;

public:
    double trailCost;
    double sum;
    state(T state, double cost1){
        cost = cost1;
        Mystate = state;
        cameFrom = nullptr;
        trailCost=cost1;
        Fheuristics=(FLT_MAX);
    }
    bool equals(state<T> s){
        return Mystate->equals(s.getMyState());

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
    void setFheuristics(double f){
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
