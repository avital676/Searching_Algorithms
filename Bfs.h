#ifndef EX4_BFS_H
#define EX4_BFS_H

#include "Searcher.h"
#include <set>

// solves a problem using BFS algorithm
class Bfs : public Searcher<Point *> {
    set<state<Point *> *> MySet;
    string search(Isearchable<Point *> *problem);
    void searchBfs(state<Point *> *start, state<Point *> *end, Isearchable<Point *> *problem);
};

#endif //EX4_BFS_H
