//
// Created by avital on 12/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H


#include "ISearcher.h"
#include "Isearchable.h"
template <typename T>
class Searcher : public ISearcher<T> {
    virtual string search(Isearchable<T> *problem) = 0;
};


#endif //EX4_SEARCHER_H
