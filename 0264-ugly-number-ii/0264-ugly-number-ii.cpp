class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> set;
        set.insert(-1);
        int k = 0, val = 1;
        while(set.size() and k < n){
            auto it = set.end();
            it--;
            val = -(*it);
            set.erase(-val);
            set.insert(1LL*-1*2*val);
            set.insert(1LL*-1*3*val);
            set.insert(1LL*-1*5*val);
            k++;

        }
        
        return val;
    }
};