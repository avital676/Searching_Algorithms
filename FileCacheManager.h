//
// Created by avital on 09/01/2020.
//

#include "CacheManager.h"
#include <functional>
#include <string>
#include <list>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

template <typename T>
class FileCacheManager : public CacheManager<T> {
private:
    unsigned int size;
    list<string> keys;
    unordered_map<string, pair<T, typename list<string>::iterator>> keyValMap;
public:
    FileCacheManager(int capacity);
    void updateCache(string key, T obj);
    void insert(string key, T obj);
    T get(string key);
    void foreach(const function<void(T &)> func);
    };