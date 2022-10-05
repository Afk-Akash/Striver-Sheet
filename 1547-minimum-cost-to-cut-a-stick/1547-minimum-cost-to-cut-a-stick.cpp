class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int N = cuts.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        // return fun(1, N-2, cuts, dp);
        // for(int last = 0; last <= N-2; last++){
        //     for(int ind = last + 1; ind <= N-2; ind++) dp[ind][last] = 0;
        // }
        
        for(int ind = N - 2; ind >= 1; ind--){
            for(int last = ind; last <= N-2; last++){
                int mini = INT_MAX;
                for(int k = ind; k <= last; k++){
                    int cost = cuts[last+1] - cuts[ind -1] + dp[ind][k - 1] + dp[k + 1][last];
                    mini = min (mini, cost);
                }
                dp[ind][last] = mini;
            }
        }
        return dp[1][N - 2];
    }
    
    int fun(int ind, int last, vector<int> &cut, vector<vector<int>> &dp){
        if(ind > last) {
            return 0;
        }
        if(dp[ind][last] != -1) return dp[ind][last];
        
        int mini = INT_MAX;
        for(int k = ind; k <= last; k++){
            int cost = cut[last+1] - cut[ind-1] + fun(ind, k-1, cut, dp) + fun(k+1, last, cut, dp);
            mini = min(mini, cost);
        }
        
        return dp[ind][last] = mini;
    }
};