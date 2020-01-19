#ifndef EX4_DFS_H
#define EX4_DFS_H

#include "Searcher.h"
#include <set>

// solves a problem using DFS algorithm
class Dfs : public Searcher<Point *> {
    string search(Isearchable<Point *> *problem);
    void searchDfs(state<Point *> *start, state<Point *> *end, Isearchable<Point *> *problem);
};

#endif //EX4_DFS_H
