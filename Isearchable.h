#ifndef EX4_ISEARCHABLE_H
#define EX4_ISEARCHABLE_H

#include "state.h"
#include <queue>
#include <string>
using namespace std;

// interface for problems that are solved by searching for a solution
template<class T>
class Isearchable {
public:
    virtual state<T>* getInitialState()=0;
    virtual bool isGoalState(state<T>* s)=0;
    virtual state<T>* getGoalState() = 0;
    virtual queue<state<T>*> getAllPossibleStates(state<T>* s)=0;
    virtual string getDirection(state<T>* son) = 0;
};

#endif //EX4_ISEARCHABLE_H
