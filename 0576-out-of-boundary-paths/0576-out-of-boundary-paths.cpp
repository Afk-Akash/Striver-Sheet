class Solution {
    int mod = 1000000000 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(51, vector<vector<int>> (51, vector<int>(51, -1)));
        return fun(startRow, startColumn, maxMove, m, n, dp)%mod;
    }
    int fun(int i, int j, int move, int row, int col, vector<vector<vector<int>>> &dp){
        if(i < 0 or i == row or j < 0 or j == col)return 1;
        if(move == 0) return 0;
        if(dp[i][j][move] != -1 ) return dp[i][j][move];
        
        int left = fun(i, j - 1, move-1, row, col, dp);
        int right = fun(i, j+1, move - 1, row, col, dp);
        int up = fun(i-1, j, move - 1, row, col, dp);
        int down = fun(i+1, j, move -1, row, col, dp);
        
        return dp[i][j][move] = (1LL*left+ right+ up + down )%mod;
    }
};