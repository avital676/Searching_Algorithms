//
// Created by noa on 12/01/2020.
//

#include "Matrix.h"
template<typename T>
Matrix<T>::Matrix(string s){
    int countRow=0;
    int countMatrix =0;
    vector<state<int>*> row;
    vector<vector<state<int>*>> matrix;

    int num;
    string word="";
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            i++;
        } else if(s[i]==',') {
            num = stoi(word);
            state<int> *s = new state<int>(num);
            row[countRow] = s;
            word = "";
        } else if (s[i]=='\n') {
            //2 last numbers:
            if (countRow==2){

            }
            matrix[countMatrix] = row;
            vector<state<int>*> row;
            countRow = 0;
            word = "";
        } else {
            word += s[i];
        }

    }


}
