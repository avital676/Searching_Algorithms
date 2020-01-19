#include "Matrix.h"
#include <limits>

// constructor: create matrix from given vector
Matrix::Matrix(vector<string> s) {
    int countCol = 0;
    vector<state<Point *> *> row1;
    vector<vector<state<Point *> *>> matrix;
    double num;
    string word = "";
    rowNum = s.size() - 2;
    for (int i = 0; i < s.size() - 2; i++) {
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] == ',') {
                num = stoi(word);
                Point *p = new Point(i, countCol);
                state<Point *> *s1 = new state<Point *>(p, num);
                s1->setTrailCost(numeric_limits<double>::max());
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
        colNum = countCol + 1;
        countCol = 0;
        word = "";
    }
    this->matrix = matrix;
    start = createStateFromString(s[s.size() - 2]);
    start->setTrailCost(start->getCost());
    end = createStateFromString(s[s.size() - 1]);
}

// create a state in matrix from s given string
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

// get the initial state in matrix
state<Point *> *Matrix::getInitialState() {
    return start;
}

// check if a given state is the goal state
bool Matrix::isGoalState(state<Point *> *s) {
    return (s->equals(*end));
}

// get the goal state of the matrix
state<Point *> *Matrix::getGoalState() {
    return end;
}

// given a state, get all the available neighbours in the matrix
queue<state<Point *> *> Matrix::getAllPossibleStates(state<Point *> *s) {
    queue<state<Point *> *> states;
    int x = s->getMyState()->x;
    int y = s->getMyState()->y;
    if (x != 0) {
        if (matrix[x - 1][y]->getCost() != -1) {
            states.push(matrix[x - 1][y]); // up
        }
    }
    if (y != colNum - 1) {
        if (matrix[x][y + 1]->getCost() != -1) {
            states.push(matrix[x][y + 1]); // right
        }
    }
    if (x != rowNum - 1) {
        if (matrix[x + 1][y]->getCost() != -1) {
            states.push(matrix[x + 1][y]); // down
        }
    }
    if (y != 0) {
        if (matrix[x][y - 1]->getCost() != -1) {
            states.push(matrix[x][y - 1]); // left
        }
    }
    return states;
}

// given a state, get the previous state and the cost by now
string Matrix::getDirection(state<Point *> *son) {
    state<Point *> *father = son->getCameFrom();
    int x = son->getMyState()->x;
    int y = son->getMyState()->y;
    string direction;
    if (father->getMyState()->x == (x + 1)) {
        direction = "Up (" + to_string(son->getTrailCost()) + ")";
        return direction;
    }
    if (father->getMyState()->x == (x - 1)) {
        direction = "Down (" + to_string(son->getTrailCost()) + ")";
        return direction;
    }
    if (father->getMyState()->y == (y + 1)) {
        direction = "Left (" + to_string(son->getTrailCost()) + ")";
        return direction;
    }
    if (father->getMyState()->y == (y - 1)) {
        direction = "Right (" + to_string(son->getTrailCost()) + ")";
        return direction;
    }
}
