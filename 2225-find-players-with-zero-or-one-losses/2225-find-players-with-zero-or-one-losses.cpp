class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> winner, loser;
        for(auto & ak : matches){
            winner[ak[0]]++;
            loser[ak[1]]++;
        }
        for(auto & a : winner){
            if(!loser.count(a.first))ans[0].push_back(a.first);
        }
        for(auto  & a : loser)if(a.second == 1)ans[1].push_back(a.first);
        return ans;
    }
};