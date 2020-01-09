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
    list<string> keys;
    unordered_map<string, pair<string, typename list<string>::iterator>> keyValMap;
public:
    FileCacheManager(int capacity);
    void updateCache(string key, string obj);
    void insert(string key, string obj);
    string get(string key);
    void foreach(const function<void(string &)> func);
    };