// LRU (Least Recently Used Cache

class LRUCache {
public:
    LRUCache(int capacity) : size(capacity) {}
    
    int get(int key) {
        if (cache.find(key) != std::end(cache)) {
            keys.remove(key);
            keys.push_front(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == std::end(cache)) {
            if (keys.size() == size) {
                int lru = keys.back();
                cache.erase(lru);
                keys.pop_back();
            }
            
            cache[key] = value;
            keys.push_front(key);
        } else {
            keys.remove(key);
            keys.push_front(key);
            cache[key] = value;
        }
    }

private:
    const int size;
    std::list<int> keys;
    std::unordered_map<int, int> cache; 
};
