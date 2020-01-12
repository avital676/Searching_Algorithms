//
// Created by avital on 12/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H


#include "ISearcher.h"
#include "Isearchable.h"

class Searcher : public ISearcher {
    virtual string search(Isearchable problem) = 0;
};


#endif //EX4_SEARCHER_H
