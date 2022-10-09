class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        // return fun(0, arr, k, dp);
        for(int i = n - 1; i >= 0; i--){
                int maxi = 0, temp = 0;
            for(int j = i; j < min(i+k, n); j++){
                maxi = max(maxi, arr[j]);
                int cost = maxi * (j - i + 1) + dp[j+1];
                temp = max(temp, cost);
            }
            dp[i] = temp;
        }
        return dp[0];
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