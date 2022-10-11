class Solution {
    string ans;
    vector<vector<bool>> dp;
public:
    Solution(){
        ans = "";
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        ans = s[0];
        dp.resize(n+1, vector<bool>(n+1,0));
        for(int i = 0; i < n; i++)dp[i][i] = 1;
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    if(j - i == 1 or dp[i+1][j-1]){
                        dp[i][j] = true;
                        if(ans.size() < j-i + 1) ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
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