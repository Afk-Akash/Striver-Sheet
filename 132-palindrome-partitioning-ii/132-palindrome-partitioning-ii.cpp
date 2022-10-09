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
        vector<int> dp(n+1, -1);
        return fun(0, s, dp)-1;
        
    }
    
    int fun(int i, string &s, vector<int> &dp){
        if(i == s.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        int mini = 1e7;
        
        for(int ind = i; ind < s.size(); ind++){
            if(isPalindrome(s, i,ind)){
                int cost = 1 + fun(ind + 1,s, dp);
            
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }
};