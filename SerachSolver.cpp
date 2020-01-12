//
// Created by avital on 12/01/2020.
//


#include "SerachSolver.h"
#include "Isearchable.h"

template <typename T>
string SerachSolver<T>::solve(Isearchable<T> problem) {
    return iSeracher.search(problem);
}

template <typename T>
SerachSolver<T>::SerachSolver(ISearcher<T> s) {
    iSeracher = s;
}
