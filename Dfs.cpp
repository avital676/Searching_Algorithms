#include "Dfs.h"

// search a path to solve the given problem
string Dfs::search(Isearchable<Point *> *problem) {
    searchDfs(problem->getInitialState(), problem->getGoalState(), problem);
    if (problem->getGoalState()->getCameFrom() == nullptr) {
        return "No path";
    }
    return backTrace(problem);

}

// use DFS
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
            evaluateNodePlus();
            s->trailCost = start->trailCost + s->getCost();
            searchDfs(s, end, problem);
        }
    }
}
