//
// Created by avital on 13/01/2020.
//

#include "BestFS.h"
#include <bits/stdc++.h>

string BestFS::search(Isearchable<Point*> *problem) {
    addToOpenQ(problem->getInitialState());
    unordered_set<state<Point*>> closed;
    while (openQsize() > 0) {
        state<Point*>* n = popOpenQ();
        closed.insert(n);
        if (n->equals(*problem->getGoalState()) {
            return backTrace(problem);
        }
    }
}
