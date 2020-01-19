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
    int evaluateNum=0;
    stack<state<Point *> *> stack;
    vector<state<Point *> *> visited;
    state<Point *> *s;
    state<Point *> *current;
    stack.push(start);
    while (!stack.empty()) {
        current = stack.top();
        stack.pop();
        evaluateNum++;
        if (!inVisited(visited, current)) {
            visited.push_back(current);
        }
        if (start->equals(*end)) {
            cout<<to_string(evaluateNum)<<endl;
            return;
        }
        queue<state<Point *> *> succ = problem->getAllPossibleStates(current);
        while (!succ.empty()) {
            s = succ.front();
            succ.pop();
            if (!inVisited(visited, s)) {
                s->setCameFrom(current);
                s->setTrailCost(current->getTrailCost() + s->getCost());
                stack.push(s);
            }
        }
    }
    cout<<to_string(evaluateNum)<<endl;
}

bool Dfs::inVisited(vector<state<Point *> *> visited, state<Point *> *current) {
    for (auto state:visited) {
        if (current->equals(*state)) {
            return true;
        }
    }
    return false;
}


