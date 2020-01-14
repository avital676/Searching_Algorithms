//
// Created by noa on 12/01/2020.
//

#include "Matrix.h"

Matrix::Matrix(vector<string> s) {
    int countCol = 0;
    int countMatrix = 0;
    vector<state<Point *> *> row1;
    vector<int> intim;
    vector<vector<state<Point *> *>> matrix;

    double num;
    string word = "";
    for (int i = 0; i < s.size() - 2; i++) {
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] == ',') {
                num = stoi(word);
                Point *p = new Point(i, countCol);
                state<Point *> *s1 = new state<Point *>(p, num);
                //intim.push_back(3);
                row1.push_back(s1);
                countCol++;
                word = "";
            } else if (s[i][j] != ' ') {
                word += s[i][j];
            }
        }
        num = stoi(word);
        Point *p = new Point(i, countCol);
        state<Point *> *s1 = new state<Point *>(p, num);
        row1.push_back(s1);
        matrix.push_back(row1);
        row1.clear();
        countCol = 0;
        word = "";
    }
    this->matrix = matrix;
    start = createStateFromString(s[s.size() - 2]);
    end = createStateFromString(s[s.size() - 1]);

}

state<Point *> *Matrix::createStateFromString(string s) {
    string x = "";
    string y = "";
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            x = temp;
            temp = "";
        } else if (s[i] != ' ') {
            temp += s[i];
        }
    }
    y = temp;
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

state<Point *> *Matrix::getGoalState() {
    return end;
}

vector<state<Point *> *> *Matrix::getAllPossibleState(state<Point *> *s) {
    vector<state<Point *> *> *states;
    int x = s->getMyState()->x;
    int y = s->getMyState()->y;
    states->push_back(matrix[x - 1][y]); // up
    states->push_back(matrix[x][y + 1]); // right
    states->push_back(matrix[x + 1][y]); // down
    states->push_back(matrix[x][y - 1]); // left
    return states;
}


if (father->getMyState()->x == x + 1) {

} else if (father->getMyState()->x == x + -1) {

} else if
