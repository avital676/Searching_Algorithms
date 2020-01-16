//
// Created by paz on 09/01/19.
//

#ifndef PROJ2_ASTAR_H
#define PROJ2_ASTAR_H


#include <map>
#include <iostream>
#include "Searcher.h"
#include "state.h"
#include <iterator>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <math.h>

class Astar : public Searcher<Point *> {
    int NumberOfNodesEvaluated = 0;
public:
    int getNumberOfNodesEvaluated() {
        return this->NumberOfNodesEvaluated;
    }

    /**
     * return value of h+g
     * @param h huristic
     * @param state
     * @param searchable
     * @return
     */
    double f(vector<vector<int>> h, state<Point *> *state, Isearchable<Point *> *searchable) {
        int a = h[state->getMyState()->x][state->getMyState()->y];
        int b = g(state, searchable);
        return a + b;
    }

    /**
     * calculate g
     * @param state
     * @param searchable
     * @return distance from the init point
     */
    double g(state<Point *> *state, Isearchable<Point *> *searchable) {
        if (state == searchable->getInitialState()) {
            return state->trailCost;
        }
        return state->getCameFrom()->trailCost + state->getCost();

    }

    /**
     * calculate h huristic - air distance
     * @param st position in matrix
     * @param searchable
     * @return
     */
    int calch(Point *st, Isearchable<Point *> *searchable) {
        int n = searchable->getObj()->size();
        int m = searchable->getObj()->at(0).size();
        int x = st->x;
        int y = st->y;
        return (n-1-x)+(m-1-y);
       // int result=  pow (n - 1 - x, 2) + pow(m - 1 - y, 2);
       // return sqrt(result);
    }

    /**
     * search a state in the map
     * @param open map of seen nodes
     * @param node
     * @return if find in the map
     */
    bool findState(multimap<double, state<Point *> *> open, state<Point *> *node) {
        multimap<double, state<Point *> *>::iterator it;
        for (it = open.begin(); it != open.end(); ++it) {
            if (it->second == node) {
                return true;
            }
            return false;
        }
    }

    /**
     * erase a state from the map
     * @param open map
     * @param node specific state
     */
    void deleteState(multimap<double, state<Point *> *> *open, state<Point *> *node) {
        typename std::multimap<double, state<Point *> *>::iterator it;
        for (it = open->begin(); it != open->end(); ++it) {
            if (it->second == node) {
                open->erase(it);
                return;
            }
        }
    }

    /**
     * init all the params for starting search
     * @param searchable
     */
    void init(Isearchable<Point *> *searchable) {
        for (vector<state<Point *> *> s:*searchable->getObj()) {
            for (state<Point *> *state:s) {
                //state->setVisited(false);
                state->setCameFrom(nullptr);
                state->trailCost = (state->getCost());
            }
        }
    }

    string search(Isearchable<Point *> *searchable) override {
        init(searchable);
        //huristic matrix- manhattan distance
        vector<vector<int>> h;
        for (int i = 0; i < searchable->getObj()->size(); i++) {
            vector<int> row;
            for (int j = 0; j < searchable->getObj()->at(0).size(); j++) {
                row.push_back(calch(new Point(i, j), searchable));
            }
            h.push_back(row);
        }
        multimap<double, state<Point *> *> open;
        list<state<Point *> *> closed;
        state<Point *> *node_current;
        state<Point *> *initial = searchable->getInitialState();
        open.insert(make_pair((initial->trailCost + calch(initial->getMyState(), searchable)), initial));
        while (!open.empty()) {
            this->NumberOfNodesEvaluated++;
            //the least f node
            node_current = open.begin()->second;
            deleteState(&open, node_current);
            //if it the goal node
            if (node_current == searchable->getGoalState()) { break; }
//            if (node_current->getMyState()->x == 0 && node_current->getMyState()->y == 2) {
//                int a = 0;
//            }
            queue<state<Point *> *> neighbours = searchable->getAllPossibleStates(node_current);
            state<Point *> *neighbour;
            while (!neighbours.empty()) {
                neighbour = neighbours.front();
                neighbours.pop();
                double currentval = node_current->trailCost + neighbour->getCost();
                //in open
                if (findState(open, neighbour)) {
                    if (g(neighbour, searchable) <= currentval) { continue; }
                    neighbour->setCameFrom(node_current);
                    // in closed
                } else if (std::find(closed.begin(), closed.end(), neighbour) != closed.end()) {
                    continue;
                    //not in close and not in open
                } else {
                    neighbour->setCameFrom(node_current);
                    open.insert(make_pair(f(h, neighbour, searchable), neighbour));
                }
                neighbour->trailCost = currentval;
                cout<<currentval<<endl;
            }
            closed.push_back(node_current);

        }
        if (node_current != searchable->getGoalState()) {
            __throw_invalid_argument("not find a way");
        }
        //return path
        return backTrace(searchable);
        //return returnPath(searchable);


    }

    /**
     * backtrack the path from goal to init
     * @param searchable
     * @return all the nodes in the path
     */
    vector<Point *> returnPath(Isearchable<Point *> *searchable) {
        state<Point *> *state = searchable->getGoalState();
        vector<Point *> path;
        while (state->getCameFrom() != nullptr) {
            path.push_back(state->getMyState());
            state = state->getCameFrom();
        }
        path.push_back(searchable->getInitialState()->getMyState());
        std::reverse(path.begin(), path.end());
//todo delete
        //cout<<searchable->getGoalState()->getCost()<<","<<this->NumberOfNodesEvaluated<<endl;
        return path;
    }

};


#endif //PROJ2_ASTAR_H