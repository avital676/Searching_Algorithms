//
// Created by avital on 09/01/2020.
//

#include "CacheManager.h"
#include <functional>
#include <string>
#include <list>
#include <unordered_map>
#include <fstream>
#include <exception>

class FileCacheManager : public CacheManager<string> {
private:
    unsigned int size;
    list<int> keys;
    unordered_map<int, pair<string, typename list<int>::iterator>> keyValMap;
    unordered_map<string, int> hashMapString;
    hash<string> hasher;
public:
    FileCacheManager(int capacity);
    void updateCache(int key, string obj);
    void insert(string key, string obj);
    string get(string key);
    void foreach(const function<void(string &)> func);
    bool isInCache(string key);
    };