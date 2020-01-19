#include <iostream>
#include "FileCacheManager.h"

    FileCacheManager::FileCacheManager(int capacity) {
        size = capacity;
    }
    void FileCacheManager::updateCache(int key, string obj) {
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
    void FileCacheManager::insert(string key, string obj) {
        int newKey = hasher(key);
        hashMapString[key]=newKey;
        // insert to cache:
        updateCache(newKey, obj);
        // insert to filesystem:
        ofstream file(to_string(newKey));
        file << obj;
        file.close();
    }

    string FileCacheManager:: get(string key) {
        string val;
        fstream file(key, ios::in | ios::binary);
        // key exists in cache:
        if (keyValMap.find(hashMapString[key]) != keyValMap.end()) {
            val = keyValMap[hashMapString[key]].first;
            // update item to be the most recently used:
            updateCache(hashMapString[key], val);
        } else if (file) { // key not in cache, check in file:
            file.read((char *) &val, sizeof(val));
            // update item to be the most recently used:
            updateCache(hashMapString[key], val);
        } else {
            file.close();
            // not in file
        }
        file.close();
        return val;
    }

bool FileCacheManager::isInCache(string key) {
    if (keyValMap.find(hashMapString[key]) != keyValMap.end()) {
        return true;
    }
    return false;
}

    void FileCacheManager::foreach(const function<void(string &)> func) {
        for (int t : keys) {
            func(keyValMap[t].first);
        }
    }

