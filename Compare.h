#ifndef EX4_COMPARE_H
#define EX4_COMPARE_H

#include "state.h"

// compares states by their trail costs (used in priority queue)
class Compare {
public:
    bool operator()(state<Point *> *s1, state<Point *> *s2) {
        if (s1->trailCost > s2->trailCost) {
            return true;
        }
        return false;
    }
};

#endif //EX4_COMPARE_H
