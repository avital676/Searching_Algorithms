#ifndef EX4_AASTAR_H
#define EX4_AASTAR_H

#include <cfloat>
#include "Searcher.h"
#include <set>
#include <stack>
#include <cstring>
#include <queue>
#include <fcntl.h>
#include "state.h"
using namespace std;

class AAStar : public Searcher<Point*> {

    // compare states by their heuristic path cost:
    class Comp {
    public:
        bool operator()(state<Point*>* left, state<Point*>* right) {
            return (left->getFheuristics()) > (right->getFheuristics());
        }
    };

public:
    // search a path to solve the given problem using A* algorithm
    string search(Isearchable<Point*>* searchable) override {
        int evaluateNum=0;
        state<Point*> *current;
        queue<state<Point*> *> neighbors;
        priority_queue<state<Point*>*, vector<state<Point*>*>, Comp> open;
        open.push(searchable->getInitialState());
        vector<state<Point*> *> closed;
        while (!open.empty()) {
            current = open.top();
            open.pop();
            evaluateNum++;
            closed.push_back(current);
            if (current->equals(*searchable->getGoalState())) {
                evaluateNodePlus();
                cout<<to_string(evaluateNum)<<endl;
                return backTrace(searchable);
            }
            neighbors = searchable->getAllPossibleStates(current);
            state<Point*> *neighbor;
            while (!neighbors.empty()) {
                neighbor= neighbors.front();
                neighbors.pop();
                if (!inOpen(open, neighbor) && !inClosed(closed, neighbor)) {
                    neighbor->setCameFrom(current);
                    neighbor->addToTrailCost(current->getTrailCost());
                    neighbor->setFheuristics(calculateF(neighbor,searchable->getGoalState()));
                    open.push(neighbor);
                    continue;
                } else if (inClosed(closed, neighbor)){
                    continue;
                }
                else if (current->getTrailCost() + neighbor->getCost() < neighbor->getTrailCost()) {
                    neighbor->setTrailCost((current->getTrailCost() + neighbor->getCost()));
                    neighbor->setFheuristics(calculateF(neighbor, searchable->getGoalState()));
                    neighbor->setCameFrom(current);
                    open = updatePriorityQ(open);
                }
            }
        }
        return "No path";
    }

    // check if a given state is in the open queue
    bool inOpen(priority_queue<state<Point*> *, vector<state<Point*> *>, Comp> p, state<Point*> *current) {
        while (!p.empty()) {
            //found state in priority/-queue
            if (current->equals(*p.top())) { return true; }
            p.pop();
        }
        return false;
    }

    // check if a given state is in the close vector
    bool inClosed(vector<state<Point*>*> closed, state<Point*>* current) {
        for (auto state:closed) {
            if (current->equals(*state)) {
                return true;
            }
        }
        return false;
    }

    // update costs of states in priority queue
    priority_queue<state<Point*>*, vector<state<Point*> *>, Comp> updatePriorityQ(priority_queue<state<Point*> *,
            vector<state<Point*> *>, Comp> p ){
        priority_queue<state<Point*> *, vector<state<Point*> *>, Comp> newQ;
        while (!p.empty()) {
            newQ.push(p.top());
            p.pop();
        }
        return newQ;
    }

    // calculate heuristic path cost
    double calculateF(state<Point*>* state1, state<Point*>* goal) {
        //manhattan distance
        double h = abs(state1->getMyState()->x - goal->getMyState()->x) +
                   abs(state1->getMyState()->y - goal->getMyState()->y);
        double g = state1->getTrailCost();
        return g + h;
    }
};
#endif //EX4AA_STAR_H