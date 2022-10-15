class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        vector<vector<int>> LCS(n+1, vector<int> (n+1, 0));
        vector<int> dp(n, 1);       //minmum 1 way of deleting string
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    LCS[i][j] = 1 + LCS[i+1][j+1];
                }
                if(LCS[i][j] >= j - i){             //it will tell if length of common substring is greater
                    dp[i] = max(dp[i], 1 + dp[j]);  //than or equal to j - i means there is no mid element 
                }                                       //in between them so we can delete
            }
        }
        return dp[0];
    }
    
  
};