//
// Created by avital on 12/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H


#include "ISearcher.h"
#include "Isearchable.h"
#include <queue>
#include <stack>

template <typename T>
class Searcher : public ISearcher<T> {
private:
    priority_queue<state<Point*>> openQ;
    int evaluateNode = 0;
protected:
    state<Point*>* popOpenQ() {
        evaluateNode++; /// MAYBE COST
        state<Point*>* s = openQ.top();
        openQ.pop();
        return s;
    }
    void addToOpenQ(state<Point*>* s) {
        openQ.push(s);
    }
    string backTrace(Isearchable<Point*> *problem) {
        state<Point*>* son = problem->getGoalState();
        state<Point*>* father = son->getCameFrom();
        stack<string> path;
        int x;
        int y;
        while (father != NULL) {
            x = son->getMyState()->x;
            y = son->getMyState()->y;

            son = father;
            father = son->getCameFrom();
        }
        (matrix[x - 1][y]); // up
        (matrix[x][y + 1]); // right
        (matrix[x + 1][y]); // down
        (matrix[x][y - 1]); // left
    }
public:
    //virtual string search(Isearchable<T>* problem) = 0;
    int openQsize() {
        return openQ.size();
    }
    int getNumOfNodesEvaluated() {
        return evaluateNode;
    }
};


#endif //EX4_SEARCHER_H
