class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i < j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return fun(0, n - 1, s, dp) - 1;
        
    }
    
    int fun(int i, int j, string &s, vector<vector<int>> &dp){
        if(isPalindrome(s,i,j))return 1;
        if(i == j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e7;
        
        for(int ind = i; ind < j; ind++){
            if(isPalindrome(s, i,ind)){
                int l = fun(i, ind, s, dp);
                int r = fun(ind+1, j, s, dp);
            
                mini = min(mini, l + r);
            }
        }
        return dp[i][j] = mini;
    }
};