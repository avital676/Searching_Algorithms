#ifndef MILESTONE2_A_STAR_H
#define MILESTONE2_A_STAR_H

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
    class Comp {
    public:
        bool operator()(state<Point*>* left, state<Point*>* right) {
            return (left->getFheuristics()) > (right->getFheuristics());
        }
    };
public:
    string search(Isearchable<Point*>* searchable) override {
        //this->searchable = searchable;
        state<Point*> *current;
        queue<state<Point*> *> neighbors;
        priority_queue<state<Point*>*, vector<state<Point*>*>, Comp> open;
        //searchable->getInitialState()->setFheuristics(0);
        open.push(searchable->getInitialState());
        vector<state<Point*> *> closed;

        while (!open.empty()) {
            current = open.top();
            open.pop();
            evaluateNodePlus();
            closed.push_back(current);
            if (current->equals(*searchable->getGoalState())) {
                evaluateNodePlus();
                return backTrace(searchable);
                //return searchable->getPath();
            }
            neighbors = searchable->getAllPossibleStates(current);
            state<Point*> *neighbor;
            while (!neighbors.empty()) {
                neighbor= neighbors.front();
                neighbors.pop();
                //first time encountering state
                if (!inOpen(open, neighbor) && !inClosed(closed, neighbor)) {
                    neighbor->setCameFrom(current);
                    neighbor->addToTrailCost(current->trailCost);
                    neighbor->setFheuristics(calculateF(neighbor,searchable->getGoalState()));
                    open.push(neighbor);
                    continue;
                    //neighbor is either in open or closed and - can improve path
                } else if (inClosed(closed, neighbor)){
                    continue;
                }
                else if (current->trailCost + neighbor->getCost() < neighbor->trailCost) {
                    neighbor->trailCost= (current->trailCost + neighbor->getCost());
                    neighbor->setFheuristics(calculateF(neighbor, searchable->getGoalState()));
                    neighbor->setCameFrom(current);
                    open = updatePriorityQ(open);
                }
            }
        }
        searchable->getGoalState()->trailCost = (-1);
        return "-1";
    }

    bool inOpen(priority_queue<state<Point*> *, vector<state<Point*> *>, Comp> p, state<Point*> *current) {
        while (!p.empty()) {
            //found state in priority/-queue
            if (current->equals(*p.top())) { return true; }
            p.pop();
        }
        return false;
    }

    bool inClosed(vector<state<Point*>*> closed, state<Point*>* current) {
        for (auto state:closed) {
            if (current->equals(*state)) {
                return true;
            }
        }
        return false;
    }

    priority_queue<state<Point*>*, vector<state<Point*> *>, Comp> updatePriorityQ(priority_queue<state<Point*> *,
            vector<state<Point*> *>, Comp> p ){
        priority_queue<state<Point*> *, vector<state<Point*> *>, Comp> newQ;
        while (!p.empty()) {
            newQ.push(p.top());
            p.pop();
        }
        return newQ;
    }

    /*  void deleteFromClose(vector<State<T>*> &closed, State<T>* del) {
         for (State<T>* state=closed.begin(); state != closed.end(); state++) {
              if (state->Equals(del)) {
                  closed.erase(state);
              }
          }
      }*/

    double calculateF(state<Point*>* state1, state<Point*>* goal) {
        //manhattan distance
        double h = abs(state1->getMyState()->x - goal->getMyState()->x) +
                   abs(state1->getMyState()->y - goal->getMyState()->y);
        double g = state1->trailCost;
        return g + h;
    }





};

#endif //MILESTONE2_A_STAR_H