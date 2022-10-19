class Solution {
    private: int mod = 1e9 + 7;
   private: int fun(int i, int j , vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == grid.size() or j == grid[0].size()){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int r = 1, d = 1, u = 1, l = 1;
        if(j < grid[0].size()-1 and grid[i][j] < grid[i][j+1])
            r =1+ fun(i, j+1, grid, dp);
        if(i < grid.size()-1 and grid[i][j] < grid[i+1][j])
            d =1+ fun(i + 1, j, grid, dp);
        if(i > 0 and grid[i][j] < grid[i-1][j])
            l = 1 + fun(i-1, j, grid, dp);
        if(j > 0 and grid[i][j] < grid[i][j-1])
            u = 1 + fun(i, j-1, grid, dp);
        
        return  dp[i][j] = max(r, max(l,max(u,d)))%mod;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        int ans = 0;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, fun(i,j, matrix, dp));
            }
        }
        return ans;
    }
};