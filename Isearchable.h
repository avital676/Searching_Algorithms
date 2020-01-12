//
// Created by noa on 12/01/2020.
//

#ifndef EX4_ISEARCHABLE_H
#define EX4_ISEARCHABLE_H

#include "state.h"
#include <vector>

using namespace std;

template<class T>
class Isearchable {
public:
    virtual state<T>* getInitialState() = 0;
    virtual bool isGoalStateSate(state<T> s) = 0;
    virtual vector<state<T>*> getAllPossibleState(state<T> s) = 0;
};

#endif //EX4_ISEARCHABLE_H
