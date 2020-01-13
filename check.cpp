//
// Created by noa on 12/01/2020.
//
#include "Searcher.h"
#include "Matrix.h"
#include "state.h"
template <typename T>
class check: public Searcher<Point*>{
    string search(Isearchable<Point*>* problem){
        state<Point*>* s = problem->getInitialState();
        return to_string(s->getCost());
    }

};
