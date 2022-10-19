class Solution {
public:
    bool fun(int ind, string &s, unordered_set<string> &dict, vector<int> &dp){
        if(ind == s.size()) return true;
        if(dp[ind] != -1) return dp[ind];
       for(int len = 1; len <= (s.size() - ind); len++){
           if(dict.find(s.substr(ind,len)) != dict.end() and fun(ind + len, s, dict, dp)) return  dp[ind] = true;
       }
        return dp[ind] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        int n = s.size();
        for(auto &word : wordDict) set.insert(word);
        vector<int> dp(s.size()+1, 1);
        // return fun(0, s, set, dp);
        for(int i = n-1; i >= 0; i--){
            bool flag = true;
            for(int len = 1; len <= s.size() - i; len++){
                if(set.find(s.substr(i,len)) != set.end() and dp[i+len]==1) {
                    dp[i] = true;
                    flag = false;
                    break;
                }
            }
            if(flag)
            dp[i] = false;
        }
        return dp[0];
    }
};