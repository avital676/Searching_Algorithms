#ifndef EX4_ISEARCHER_H
#define EX4_ISEARCHER_H

#include "Isearchable.h"
#include <string>
using namespace std;

// interface for searchers
template <typename T>
class ISearcher {
public:
    virtual string search(Isearchable<T>* problem) = 0;
};

#endif //EX4_ISEARCHER_H
