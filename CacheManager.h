//
// Created by avital on 09/01/2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include <string>
using namespace std;

template <typename T>
class CacheManager {
public:
    CacheManager()= default;
    virtual void insert(string key, T obj) = 0;
    virtual T get(string key) = 0;
};


#endif //EX4_CACHEMANAGER_H
