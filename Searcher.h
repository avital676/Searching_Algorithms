//
// Created by avital on 12/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H


#include "ISearcher.h"
#include "Isearchable.h"
#include <queue>
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
        while (father != NULL) {

            son = father;
            father = son->getCameFrom();
        }
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
