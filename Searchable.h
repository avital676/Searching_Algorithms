//
// Created by avital on 12/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H


#include "Isearchable.h"

class Searchable : public Isearchable<Point*>{
public:
    state<Point*>* getInitialState() {
        return nullptr;
    }
    bool isGoalStateSate(state<Point*> s) {
        return true;
    }
    virtual vector<state<Point*>*> getAllPossibleState(state<Point*> s) = 0;
};


#endif //EX4_SEARCHABLE_H
