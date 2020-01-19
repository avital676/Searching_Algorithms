#include "BestFS.h"
#include <unordered_set>

// search a path to solve the given problem
string BestFS::search(Isearchable<Point *> *problem) {
    int evaluateNum=0;
    addToOpenQ(problem->getInitialState());
    unordered_set<state<Point *> *> closed;
    while (openQsize() > 0) {
        evaluateNum++;
        state<Point *> *n = popOpenQ();
        closed.insert(n);
        if (n->equals(*problem->getGoalState())) {
            cout<<to_string(evaluateNum)<<endl;
            return backTrace(problem);
        }
        queue<state<Point *> *> succ = problem->getAllPossibleStates(n);
        state<Point *> *s;
        while (!succ.empty()) {
            s = succ.front();
            succ.pop();
            if ((closed.find(s) == closed.end()) && (!isInOpen(s))) {
                s->setTrailCost(n->getTrailCost() + s->getCost());
                s->setCameFrom(n);
                addToOpenQ(s);
            } else if ((n->getTrailCost() + s->getCost()) < s->getTrailCost()) {
                s->setTrailCost(n->getTrailCost() + s->getCost());
                s->setCameFrom(n);
                if (!isInOpen(s)) {
                    addToOpenQ(s);
                } else {
                    updateOpenQ(s);
                }
            }
        }
    }
    return "No path";
}
