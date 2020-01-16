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
//this is abstract class - for help the use of algoritem.
using namespace std;
template<typename T>
class Searcher : public ISearcher<T> {
private:
    priority_queue<state<Point *> *, vector<state<Point *> *>, Compare> openQ;
    int evaluateNode = 0;
protected:
//the func check if the state is in open queue
    bool isInOpen(state<Point *> *s) {
        vector<state<Point *> *> outFromQ;
        bool found = false;
        state<Point *> *firstInQ;
        //check the all queue until you find.
        while (!openQ.empty()) {
            firstInQ = openQ.top();
            //check if we find - if not pop him out and save for later.
            if (!firstInQ->equals(*s)) {
                outFromQ.push_back(firstInQ);
                openQ.pop();
                //if you find - break.
            } else {
                found = true;
                break;
            }
        }
        //push back all the states we poped.
        for (int i = 0; i < outFromQ.size(); i++) {
            openQ.push(outFromQ[i]);
        }
        return found;
    }
    //pop the first element in queue and return him.
    state<Point *> *popOpenQ() {
        evaluateNode++;
        state<Point *> *s = openQ.top();
        openQ.pop();
        return s;
    }
//update the s states - that he will be on the top of the queue.
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
//add to openQ.
    void addToOpenQ(state<Point *> *s) {
        openQ.push(s);
    }
//return the all string to client - check from the last state to the first how the final path look like.
    string backTrace(Isearchable<Point *> *problem) {
        state<Point *> *son = problem->getGoalState();
        stack<string> pathStack;
        int x;
        int y;
        //push into path stack the all path.
        while (son != problem->getInitialState()) {
            pathStack.push(problem->getDirection(son));
            son = son->getCameFrom();
        }
        string trace = to_string(getNumOfNodesEvaluated()) + "\n";
        //chenge the stack into string.
        while (!pathStack.empty()) {
            trace += pathStack.top();
            pathStack.pop();
            if (pathStack.size()!=0) {
                trace += ", ";
            }
        }
        cout<<trace<<endl;
        cout<<getNumOfNodesEvaluated()<<endl;
        return trace;
    }

public:
    int openQsize() {
        return openQ.size();
    }

    int getNumOfNodesEvaluated() {
        return evaluateNode;
    }
    priority_queue<state<Point *> *, vector<state<Point *> *>, Compare> getOpenQ(){
        return openQ;
    }
    void evaluateNodePlus(){
        evaluateNode++;
    }
};


#endif //EX4_SEARCHER_H
