//
// Created by noa on 14/01/2020.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include "Searcher.h"
#include <set>
class Dfs : public Searcher<Point *> {
    set<state<Point*>*> MySet;
    string search(Isearchable<Point *> *problem);
    void searchDfs(state<Point*>* start, state<Point*>* end,Isearchable<Point *> *problem );
};


#endif //EX4_DFS_H
