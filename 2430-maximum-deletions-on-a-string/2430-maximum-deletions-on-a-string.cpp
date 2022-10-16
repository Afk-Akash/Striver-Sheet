class Solution {
    
public:
    int fun(int ind, string_view s, vector<int> &dp){
        if(dp[ind] != -1) return dp[ind];
        
        int ans = 1;
        for(int i = 1; i <= (s.size() - ind)/2; i++){
            if(s.substr(ind, i) == s.substr(ind+i, i)){
                int k = 1 + fun(ind + i, s, dp);
                ans = max(ans, k);
            }
        }
        return dp[ind] = ans;
    }
    void optimize(string_view s, vector<int> &dp){
        int n = s.size();
        int k = n - 1;
        
        while(k > 0 and s[k] == s[k-1])k--;
        for(int i = k + 1; i < n; i++)dp[i] = n - i;
    }
    
    int deleteString(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        optimize(s,dp);
        return fun(0, s, dp);
    }
};