//
// Created by noa on 14/01/2020.
//

#include "Dfs.h"

string Dfs::search(Isearchable<Point *> *problem) {
    searchDfs(problem->getInitialState(), problem->getGoalState(), problem);
    return backTrace(problem);

}

void Dfs::searchDfs(state<Point *> *start, state<Point *> *end, Isearchable<Point *> *problem) {
    MySet.insert(start);
    state<Point *> *s;
    if (start->equals(*end)) {
        return;
    }
    queue<state<Point *> *> succ = problem->getAllPossibleStates(start);
    while (!succ.empty()) {
        s = succ.front();
        succ.pop();
        set<state<Point *> *>::iterator it = MySet.find(s);
        if (it == MySet.end()) {
            s->setCameFrom(start);
            s->trailCost = start->trailCost + 1;
            searchDfs(s, end, problem);
        }
    }
}


