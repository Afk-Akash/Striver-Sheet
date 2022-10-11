class Solution {
    string ans;
    vector<vector<int>> dp;
public:
    Solution(){
        ans = "";
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        ans = s[0];
        dp.resize(n+1, vector<int>(n+1,-1));
        fun(0, n-1, s);
        return ans;
    }
    
    bool fun(int i, int j, string &s){
        if(i == j)return true;
        if(i > j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            if(fun(i+1, j-1, s) == true){
                if(ans.size() < j-i+1)ans = s.substr(i,j-i+1);
                return dp[i][j] = true;
            }
        }
            fun(i+1, j, s);
            fun(i, j-1, s);
        return dp[i][j] = false;
    }
};