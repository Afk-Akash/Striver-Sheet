class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> mp;
        for(auto & ak : matches){
            if(!mp.count(ak[0])) mp[ak[0]] = 0;
            mp[ak[1]]++;
            
        }
        for(auto & a : mp){
            if(a.second == 0)ans[0].push_back(a.first);
            if(a.second == 1) ans[1].push_back(a.first);
        }
        return ans;
    }
};