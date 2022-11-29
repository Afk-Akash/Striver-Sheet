class RandomizedSet {
    unordered_set<int> set;
    int size;
public:
    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        bool flag = false;
        if(set.find(val) == set.end()) {
            flag = true;
            set.insert(val);
            size++;
        }
        
        return flag;
    }
    
    bool remove(int val) {
        bool flag = false;
        
        if(set.find(val) != set.end()) 
        {
            size--;
            flag = true;
            set.erase(val);
        }
        return flag;
    }
    
    int getRandom() {
        int rand = random()%size;
        auto it = set.begin();
        while(rand--)it++;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */