//
// Created by avital on 12/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include <iostream>
#include "ISearcher.h"
#include "Isearchable.h"
#include <queue>
#include <stack>
#include "Compare.h"
using namespace std;
template<typename T>
class Searcher : public ISearcher<T> {
private:
    priority_queue<state<Point *> *, vector<state<Point *> *>, Compare> openQ;
    int evaluateNode = 0;
protected:
    bool isInOpen(state<Point *> *s) {
        vector<state<Point *> *> outFromQ;
        bool found = false;
        state<Point *> *firstInQ;
        while (!openQ.empty()) {
            firstInQ = openQ.top();
            if (!firstInQ->equals(*s)) {
                outFromQ.push_back(firstInQ);
                openQ.pop();
            } else {
                found = true;
                break;
            }
        }
        for (int i = 0; i < outFromQ.size(); i++) {
            openQ.push(outFromQ[i]);
        }
        return found;
    }

    state<Point *> *popOpenQ() {
        evaluateNode++; /// MAYBE COST
        state<Point *> *s = openQ.top();
        openQ.pop();
        return s;
    }

    void updateOpenQ(state<Point *> *s) {
        vector<state<Point *> *> outFromQ;
        state<Point *> *firstInQ;
        while (!openQ.empty()) {
            firstInQ = openQ.top();
            if (!firstInQ->equals(*s)) {
                outFromQ.push_back(firstInQ);
                openQ.pop();
            } else {
                openQ.pop();
                break;
            }
        }
        for (int i = 0; i < outFromQ.size(); i++) {
            openQ.push(outFromQ[i]);
        }
    }

    void addToOpenQ(state<Point *> *s) {
        openQ.push(s);
    }

    string backTrace(Isearchable<Point *> *problem) {
        state<Point *> *son = problem->getGoalState();
        stack<string> pathStack;
        int x;
        int y;
        while (son != problem->getInitialState()) {
            pathStack.push(problem->getDirection(son));
            son = son->getCameFrom();
        }
        string trace = "";
        while (!pathStack.empty()) {
            trace += pathStack.top();
            trace += ", ";
            pathStack.pop();
        }
        cout<<trace<<endl;
        return trace;
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
