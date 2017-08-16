/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

/* O(1), O(n) */
class LRUCache {
public:
    LRUCache(int capacity) : cap_(capacity) {

    }

    int get(int key) {
        if (map_.find(key) != map_.end()) {
            auto val = (map_[key]) -> second;
            update(key, val);
            return val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (list_.size() >= cap_ && map_.find(key) == map_.end()) {
            map_.erase(list_.back().first);
            list_.pop_back();
        }
        update(key, value);
    }
private:
    int cap_;
    list<pair<int, int>> list_;
    unordered_map<int, list<pair<int, int>>::iterator> map_;

    void update(int key, int val) {
        if (map_.find(key) != map_.end()) {
            auto it = map_[key];
            list_.erase(it);
        }
        list_.push_front({key, val});
        map_[key] = &list_.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
