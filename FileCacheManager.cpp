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
    FileCacheManager(int capacity) {
        size = capacity;
    }

    void updateCache(string key, T obj) {
        // check if already in cache:
        if (keyValMap.find(key) != keyValMap.end()) {
            keyValMap.erase(key);
            keys.remove(key);
        } else if (keys.size() == size) {
            // key isn't in cache and cache is full:
            keyValMap.erase(keys.back());
            keys.pop_back();
        }
        // update in cache and keys list:
        keys.push_front(key);
        keyValMap[key] = {obj, keys.begin()};
    }

    void insert(string key, T obj) {
        // insert to cache:
        updateCache(key, obj);
        // insert to filesystem:
        fstream file;
        file.open(obj.class_name + key, ios::out | ios::binary);
        // delete old content of file, if exists:
        file.clear();
        // write object to file:
        file.write((char *) &obj, sizeof(obj));
        file.close();
    }

    T get(string key) {
        T val;
        fstream file(val.class_name + key, ios::in | ios::binary);
        // key exists in cache:
        if (keyValMap.find(key) != keyValMap.end()) {
            val = keyValMap[key].first;
            // update item to be the most recently used:
            updateCache(key, val);
        } else if (file) { // key not in cache, check in file:
            file.read((char *) &val, sizeof(val));
            // update item to be the most recently used:
            updateCache(key, val);
        } else {
            file.close();
            // not in file, throw exception:
            return NULL;
        }
        file.close();
        return val;
    }

    void foreach(const function<void(T &)> func) {
        for (string t : keys) {
            func(keyValMap[t].first);
        }
    }
};
