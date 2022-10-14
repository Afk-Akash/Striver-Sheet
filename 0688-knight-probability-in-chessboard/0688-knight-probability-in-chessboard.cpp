class Solution {
public:

    double totalCount(int n, int moves, int row, int col,vector<vector<vector<double>>> &dp){
        if(row < 0 or row >= n or col < 0 or col >= n)return 0;
        if(moves == 0) return 1;
        if(dp[row][col][moves] != -1) return dp[row][col][moves];
        double a1 = totalCount(n, moves - 1, row - 2, col - 1, dp);
        double a2 = totalCount(n, moves - 1, row - 1, col - 2, dp);
        double a3 = totalCount(n, moves - 1, row - 2, col + 1, dp);
        double a4 = totalCount(n, moves - 1, row - 1, col + 2, dp);
        double a5 = totalCount(n, moves - 1, row + 1, col - 2, dp);
        double a6 = totalCount(n, moves - 1, row + 2, col - 1, dp);
        double a7 = totalCount(n, moves - 1, row + 1, col + 2, dp);
        double a8 = totalCount(n, moves - 1, row + 2, col + 1, dp);
        
        double total = (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8);
        return dp[row][col][moves] = total/8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1,vector<double>(k+1, -1)));
        double total = totalCount(n, k, row, column, dp);
        
        return total;
    }
};