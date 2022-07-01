class MyHashMap {
private:
    map<int, int> Map;
public:
    MyHashMap() {
        Map.clear();
    }
    
    void put(int key, int value) {
        if (Map.find(key) == Map.end()){
            Map.insert(make_pair(key, value));
        }
        else {
            Map[key] = value;
        }
    }
    
    int get(int key) {
        if (Map.find(key) == Map.end()){
            return -1;
        }
        return Map[key];
    }
    
    void remove(int key) {
        Map.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */