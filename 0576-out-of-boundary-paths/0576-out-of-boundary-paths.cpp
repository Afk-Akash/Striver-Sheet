class Solution {
    int mod = 1000000000 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+2, vector<vector<int>> (n+2, vector<int>(maxMove+1, 0)));
        // return fun(startRow+1, startColumn+1, maxMove, m, n, dp)%mod;
//         for(int j=0; j < n+2; j++ ){
//             for(int k = 0; k <= maxMove; k++)dp[0][j][k] = 1;
//         }
        
//         for(int i=0; i < m+2; i++ ){
//             for(int k = 0; k <= maxMove; k++)dp[i][0][k] = 1;
//         }
//         for(int i = m; i <=m+1; i++){
//             for(int j =0; j < n+2; j++)for(int k = 0; k <= maxMove; k++)dp[i][j][k] = 1;
//         }
        
//         for(int i = n; i <=n+1; i++){
//             for(int j =0; j < m+2; j++)for(int k = 0; k <= maxMove; k++)dp[j][i][k] = 1;
//         }
        for(int k = 1; k <= maxMove; k++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    int left = j == 0 ? 1 : dp[i][j-1][k-1];
                    int right = j == n-1 ? 1 : dp[i][j+1][k-1];
                    int up = i == m -1? 1 : dp[i+1][j][k-1];
                    int down = i == 0 ? 1 : dp[i-1][j][k-1];

                    dp[i][j][k] = (1LL*left+ right+ up + down )%mod;
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
    int fun(int i, int j, int move, int row, int col, vector<vector<vector<int>>> &dp){
        if(i == 0 or i > row or j == 0 or j > col)return 1;
        if(move == 0) return 0;
        if(dp[i][j][move] != -1 ) return dp[i][j][move];
        
        int left = fun(i, j - 1, move-1, row, col, dp);
        int right = fun(i, j+1, move - 1, row, col, dp);
        int up = fun(i-1, j, move - 1, row, col, dp);
        int down = fun(i+1, j, move -1, row, col, dp);
        
        return dp[i][j][move] = (1LL*left+ right+ up + down )%mod;
    }
};