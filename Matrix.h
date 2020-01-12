//
// Created by noa on 12/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#include <vector>
#include "state.h"
#include <string>

using namespace std;
template<typename T>
class Matrix {
private:
    vector<vector<state<T>*>> matrix;
    state<T> start;
    state<T> end;
public:
    Matrix(vector<string> s);
    state<T> createStateFromString(string s);
};


#endif //EX4_MATRIX_H
