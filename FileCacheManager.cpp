#include "FileCacheManager.h"
template <typename T>
    FileCacheManager<T>::FileCacheManager(int capacity) {
        size = capacity;
    }
template <typename T>
    void FileCacheManager<T>::updateCache(string key, T obj) {
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
template <typename T>
    void FileCacheManager<T>::insert(string key, T obj) {
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
template <typename T>
    T FileCacheManager<T>:: get(string key) {
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
template <typename T>
    void FileCacheManager<T>::foreach(const function<void(T &)> func) {
        for (string t : keys) {
            func(keyValMap[t].first);
        }
    }

