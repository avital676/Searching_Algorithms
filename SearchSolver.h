#ifndef EX4_SEARCHSOLVER_H
#define EX4_SEARCHSOLVER_H

#include <string>
#include "Solver.h"
#include "ISearcher.h"
#include "Isearchable.h"

// object adapter: solver and searcher
template <typename T>
class SearchSolver : public Solver<Isearchable<T>*, string>{
public:
    SearchSolver(ISearcher<T> *s) {
        iSeracher = s;
    }
    ISearcher<T>* iSeracher;
    string solve(Isearchable<T>* problem) {
        return iSeracher->search(problem);

    }
};

#endif //EX4_SEARCHSOLVER_H
