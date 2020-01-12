//
// Created by noa on 12/01/2020.
//
#include "Searcher.h"
#include "Matrix.h"
#include "state.h"
template <typename T>
class check: public Searcher<T>{
    string search(Isearchable<T> problem){
        state<T> s = problem.getInitialState();
        return to_string(s.getCost());
    }

};
