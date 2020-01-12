//
// Created by avital on 12/01/2020.
//

#ifndef EX4_ISEARCHER_H
#define EX4_ISEARCHER_H

#include "Isearchable.h"
#include <string>

using namespace std;

template <typename T>
class ISearcher {
public:
    virtual string search(Isearchable<T> problem) = 0;
};


#endif //EX4_ISEARCHER_H
