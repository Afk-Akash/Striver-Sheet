class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return fun(0, arr, k, dp);
    }
    
    int fun(int ind, vector<int> &v, int &k, vector<int> &dp){
        if(ind == v.size() ) return 0;
        if(dp[ind] != -1) return dp[ind];
        int maxi = 0, ans = 0;
        for(int i = ind; i < min(ind+k, (int)v.size()); i++){
            maxi = max(maxi,v[i]);
            int cost = maxi * (i - ind + 1) + fun(i+1, v, k, dp);
            ans = max(ans, cost);
        }
        return dp[ind] = ans;
    }
};