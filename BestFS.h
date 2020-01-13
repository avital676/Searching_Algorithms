//
// Created by avital on 13/01/2020.
//

#ifndef EX4_BESTFS_H
#define EX4_BESTFS_H


#include "Searcher.h"

class BestFS : public Searcher<Point*> {
    string search(Isearchable<Point*>* problem);
};


#endif //EX4_BESTFS_H
