class RandomizedSet {
    unordered_map<int, int> mpp;
    int size;
    vector<int> v;
public:
    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        bool flag = false;
        if(mpp.find(val) == mpp.end()) {
            flag = true;
            mpp[val] = size;
            v.push_back(val);
            size++;
        }
        
        return flag;
    }
    
    bool remove(int val) {
        bool flag = false;
        
        if(mpp.find(val) != mpp.end()) 
        {
            size--;
            int last = v.back();
            v[mpp[val]] = last;
            v.pop_back();
            mpp[last] = mpp[val];
            flag = true;
            mpp.erase(val);
        }
        return flag;
    }
    
    int getRandom() {
        int rand = random()%size;
        return v[rand];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */