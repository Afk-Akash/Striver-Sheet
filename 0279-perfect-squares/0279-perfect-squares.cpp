class Solution {
    vector<int> v;
public:
    Solution(){
        for(int i = 1; i < 105; i++){
            v.push_back(i*i);
        }
    }
    
    
    int numSquares(int n) {
        // for(int i = 0; i < 30; i++)cout<<v[i]<<" ";
        vector<vector<int>> dp(10005, vector<int>(105, -1));
        return fun(v, 103, n, dp);
    }
    int fun(vector<int> &sqr, int ind, int n, vector<vector<int>> & dp){
        if(n == 0){
            return 0;
        }
        if(ind < 0)return 1e4;
        if(dp[n][ind] != -1) return dp[n][ind];
        
        int np = fun(sqr, ind-1, n, dp);
        int p = 1e4;
        if(sqr[ind] <= n){
            p = 1 + fun(sqr, ind, n - sqr[ind], dp);
        }
        
        return dp[n][ind] = min(np, p);
    }
};