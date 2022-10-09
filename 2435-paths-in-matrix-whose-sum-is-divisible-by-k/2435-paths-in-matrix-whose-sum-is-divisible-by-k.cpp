class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1,vector<int> (51,-1)));
        return fun(0, 0, 0, grid, k, dp);
    }
    
    int fun(int i, int j, int sum, vector<vector<int>> &mat, int k, vector<vector<vector<int>>>&dp){
        
        if(i == mat.size() -1 and j == mat[0].size()){
            if(sum % k == 0) return dp[i][j][sum] = 1;
            return dp[i][j][sum] = 0;
        }
        if(i >= mat.size() or j >= mat[0].size()) return dp[i][j][sum] = 0;
        
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        
        int p = fun(i+1, j, (sum + mat[i][j])%k, mat, k, dp);
        int pp = fun(i, j+1, (sum + mat[i][j])%k, mat, k, dp);
        
        return dp[i][j][sum] = (p+pp)%1000000007;
    }
};