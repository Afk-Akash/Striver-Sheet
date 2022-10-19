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
        for(int i = ind + 1;i < v.size() and v[i] <= v[ind] + jump+1; i++){
            bool flag = false;
            if(v[i] - v[ind] == jump - 1){
                k = jump - 1;
                flag = true;
            }
            if(v[i] - v[ind] == jump) {
                k = jump;
                flag = true;
            }
            if(v[i] - v[ind] == jump + 1) {
                k = jump + 1;
                flag = true;
            }
            if(flag)
                if(fun(i, k, v, dp)) return dp[ind][jump] = 1;
        }
        return dp[ind][jump] = false;
    }
};