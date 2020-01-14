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
        if (n->equals(*problem->getGoalState())) {
            return backTrace(problem);
        }
        queue<state<Point*>*>* succ = problem->getAllPossibleStates(n);
        state<Point*>* s;
        while (!succ->empty()) {
            s = succ->front();
            succ->pop();
            if ((closed.find(s) == closed.end()) && (!isInOpen(s)) {
                s->setCameFrom(n);
                addToOpenQ(s);
            } else if (s->getCameFrom().trailCost + s->getCost() < s.trailCost) {
                if (isInOpen(s)) {
                    addToOpenQ(s);
                } else {
                    updateOpenQ(s);
                }
            }
        }
    }
}
