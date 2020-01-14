//
// Created by noa on 12/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#include <vector>
#include "state.h"
#include <string>
#include "Searchable.h"

using namespace std;
class Matrix : public Isearchable<Point*> {
private:
    vector<vector<state<Point*>*>> matrix;
    state<Point*>* start;
    state<Point*>* end;
    int rowNum;
    int colNum;
public:
    Matrix();
    Matrix(vector<string> s);
    state<Point*>* createStateFromString(string s);
    state<Point*>* getInitialState();
    state<Point*>* getGoalState();
    bool isGoalStateSate(state<Point*>* s);
    queue<state<Point*>*> getAllPossibleStates(state<Point*>* s);
    string getDirection(state<Point*> *son);
};


#endif //EX4_MATRIX_H
