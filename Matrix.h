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
class Matrix : public Searchable {
private:
    vector<vector<state<Point*>*>> matrix;
    state<Point*>* start;
    state<Point*>* end;
public:
    Matrix();
    Matrix(vector<string> s);
    state<Point*>* createStateFromString(string s);
    state<Point*>* getInitialState();
    bool isGoalStateSate(state<Point*> s);
    vector<state<Point*>*> getAllPossibleState(state<Point*> s);
};


#endif //EX4_MATRIX_H
