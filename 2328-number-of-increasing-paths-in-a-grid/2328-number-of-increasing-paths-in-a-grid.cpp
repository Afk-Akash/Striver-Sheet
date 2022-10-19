class Solution {
    int mod = 1e9 + 7;
public:
    int fun(int i, int j , vector<vector<int>> &grid, vector<vector<int>> &dp){
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
        
        return  dp[i][j] = (r+d+ u+l-3)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        long long ans = 0, row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row, vector<int> (col, -1));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans += 1LL*fun(i, j, grid, dp)%mod;
            }
        }
        return ans % mod;
    }
};