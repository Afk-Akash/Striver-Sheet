class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int N = cuts.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return fun(0, n, 0, N, cuts, dp);
    }
    
    int fun(int i, int j, int ind, int last, vector<int> &cut, vector<vector<int>> &dp){
        if(ind == last) return 0;
        if(dp[ind][last] != -1) return dp[ind][last];
        
        int mini = INT_MAX;
        for(int k = ind; k < last; k++){
            int atCut = cut[k];
            int cost = (j-i) + fun(i, atCut, ind, k, cut, dp) + fun(atCut, j, k+1, last, cut, dp);
            mini = min(mini, cost);
        }
        
        return dp[ind][last] = mini;
    }
};