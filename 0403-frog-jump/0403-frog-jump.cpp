class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int,unordered_set<int> > mp;
        mp[1] = {1};
        for(int i = 1; i < n; i++){
            int pos = stones[i];
            for(auto &a : mp[pos]){
                mp[pos + a].insert(a);
                mp[pos + a-1].insert(a-1);
                mp[pos + a+1].insert(a+1);
            }
        }
        if(mp[stones[n-1]].size()) return 1;
        return false;
    }
};