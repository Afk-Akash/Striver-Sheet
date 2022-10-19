class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n  = stones.size();
        if(n == 2) return stones[1] - stones[0] == 1;
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fun(0, 0, stones, dp);
    }
    
    bool fun(int ind, int jump, vector<int> &v, vector<vector<int>> &dp){
        if(ind == v.size()-1) return true;
        if(dp[ind][jump] != -1) return dp[ind][jump];
        int k = jump;
        for(int i = -1; i <= 1; i++){
            k = jump + i;
            if(k <= 0)continue;
            int index = lower_bound(v.begin(), v.end(), v[ind]+k) - v.begin();
            if(index <= v.size() - 1 and v[index] - v[ind] == k) if(fun(index, k, v, dp)) return dp[ind][jump]=true;
        }
        
        return dp[ind][jump] = false;
    }
};