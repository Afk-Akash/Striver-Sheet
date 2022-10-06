class TimeMap {
    unordered_map<string, map<int, string>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
        mp[key][time] = value;
    }
    
    string get(string key, int time) {
        auto it = mp[key].lower_bound(time);
        if(it == mp[key].begin() and it->first != time) return "";
        if(it->first == time) return it->second;
        it--;
        return it -> second;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */