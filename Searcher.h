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
    bool isInOpen(state<Point*>* s) {
        vector<state<Point*>*> outFromQ;
        state<Point*>* firstInQ= openQ.pop();
        while (!firstInQ->equals(*s)){
            outFromQ.push_back(firstInQ);
            if (!openQ.empty()) {
                firstInQ = openQ.pop();
            } else {
                return false;
            }
        }
        openQ.push(firstInQ);
        for (int i=0; i<outFromQ.size(); i++){
            openQ.push(outFromQ[i]);
        }
        return true;
    }

    state<Point*>* popOpenQ() {
        evaluateNode++; /// MAYBE COST
        state<Point*>* s = openQ.top();
        openQ.pop();
        return s;
    }

    void updateOpenQ(state<Point*>* s) {
        vector<state<Point*>*> outFromQ;
        state<Point*>* firstInQ= openQ.pop();
        while (!firstInQ->equals(*s)){
            outFromQ.push_back(firstInQ);
            if (!openQ.empty()) {
                firstInQ = openQ.pop();
            }
        }
        for (int i=0; i<outFromQ.size(); i++){
            openQ.push(outFromQ[i]);
        }
    }

    void addToOpenQ(state<Point*>* s) {
        openQ.push(s);
    }

    string backTrace(Isearchable<Point*> *problem) {
        state<Point*>* son = problem->getGoalState();
        stack<string> pathStack;
        int x;
        int y;
        while (son != problem->getInitialState()) {
            pathStack.push(problem->getDirection(son));
        }
        string trace = "";
        while(!pathStack.empty()) {
            trace += pathStack.top();
            trace += ", ";
            pathStack.pop();
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
