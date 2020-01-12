//
// Created by noa on 12/01/2020.
//

#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(vector<string> s) {
    int countRow = 0;
    int countMatrix = 0;
    vector<state<int> *> row;
    vector<vector<state<int> *>> matrix;

    int num;
    string word = "";
    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = 0; j < s[i].length(); i++) {
            if (s[i][j] == ' ') {
                j++;
            } else if (s[i][j] == ',') {
                num = stoi(word);
                state<int> *s = new state<int>(num);
                row[countRow] = s;
                word = "";
            } else {
                word += s[i];
            }
        }
        matrix[countMatrix] = row;
        vector<state<int> *> row;
        countRow = 0;
        word = "";
    }
    this->matrix = matrix;
    string start = createStateFromString(s[s.size()-1]);
    string end = createStateFromString(s[s.size()]));
    this->start=start;
    this->end=end;
}
template<typename T>
state<T> Matrix<T>::createStateFromString(string s){
    string x="";
    string y="";
    for (int i=0; i<s.length(); i++){
        if (s[i]==' '){
            i++;
        }
        if (s[i]==','){
            x = s.substr(0,i);
            y = s.substr(i, s.length());
            break;
        }
    }
    int Ix = stoi(x);
    int Iy = stoi(y);
    return matrix[Ix][Iy];
}


