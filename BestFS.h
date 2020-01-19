#ifndef EX4_BESTFS_H
#define EX4_BESTFS_H

#include "Searcher.h"

// solves a problem using BestFS algorithm
class BestFS : public Searcher<Point*> {
    string search(Isearchable<Point*>* problem);
};


#endif //EX4_BESTFS_H
