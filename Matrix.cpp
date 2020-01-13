//
// Created by noa on 12/01/2020.
//

#include "Matrix.h"

Matrix::Matrix(vector<string> s) {
    int countRow = 0;
    int countMatrix = 0;
    vector<state<Point *> *> row;
    vector<vector<state<Point *> *>> matrix;

    double num;
    string word = "";
    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = 0; j < s[i].length(); i++) {
            if (s[i][j] == ' ') {
                j++;
            } else if (s[i][j] == ',') {
                num = stoi(word);
                Point *p = new Point(i, j);
                state<Point *> *s1 = new state<Point *>(p, num);
                row[countRow] = s1;
                word = "";
            } else {
                word += s[i];
            }
        }
        matrix.push_back(row);
        vector<state<Point *> *> row;
        countRow = 0;
        word = "";
    }
    this->matrix = matrix;
    start = createStateFromString(s[s.size() - 1]);
    end = createStateFromString(s[s.size()]);

}

state<Point *> *Matrix::createStateFromString(string s) {
    string x = "";
    string y = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            i++;
        }
        if (s[i] == ',') {
            x = s.substr(0, i);
            y = s.substr(i, s.length());
            break;
        }
    }
    int Ix = stoi(x);
    int Iy = stoi(y);
    return matrix[Ix][Iy];
}

state<Point *> *Matrix::getInitialState() {
    return start;
}

bool Matrix::isGoalStateSate(state<Point *> *s) {
    return (s->equals(*end));
}

vector<state<Point *> *> *Matrix::getAllPossibleState(state<Point *> *s) {
    vector<state<Point *> *> *states;
    int x = s->getMyState()->x;
    int y = s->getMyState()->y;
    states->push_back(matrix[x - 1][y]);
    states->push_back(matrix[x][y + 1]);
    states->push_back(matrix[x + 1][y]);
    states->push_back(matrix[x][y - 1]);
    return states;
}


