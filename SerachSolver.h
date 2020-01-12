//
// Created by avital on 12/01/2020.
//

#ifndef EX4_SERACHSOLVER_H
#define EX4_SERACHSOLVER_H

#include <string>
#include "Solver.h"
#include "ISearcher.h"
#include "Isearchable.h"

// object adapter: solver and searcher
template <typename T>
class SerachSolver : public Solver<Isearchable<T>, string>{
public:
    SerachSolver(ISearcher<T> s);
    ISearcher<T> iSeracher;
    string solve(Isearchable<T> problem);
};


#endif //EX4_SERACHSOLVER_H
