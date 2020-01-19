#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include <string>
using namespace std;

// cache interface- saves solutions of recently solved problems
template <typename T>
class CacheManager {
public:
    virtual void insert(string key, T obj) = 0;
    virtual T get(string key) = 0;
    virtual bool isInCache(string key)=0;
};

#endif //EX4_CACHEMANAGER_H
