class Solution {
public:
    int squareCounter(vector<int> &pillar){
        int n = pillar.size();
        
        vector<int> HorW(n);
        for(int i = 0; i < n; i++){
            HorW[i] = pillar[i] ? 1 : 0;
            for(int j = i + 1; j < min(n, i+pillar[i]); j++){
                if(pillar[j] <= HorW[i])break;
                HorW[i] = j-i+1;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += HorW[i];
        }
        return ans;
        
    }
    int countSquares(vector<vector<int>>& m) {
        int row = m.size(), col = m[0].size(), ans = 0;
        vector<vector<int>> dp(row, vector<int> (col,0));
        for(int i = 0; i < row; i++){
            dp[i][0] = m[i][0];
            if(dp[i][0]==1)ans++;
        }
        for(int i = 1; i < col; i++){
            dp[0][i] = m[0][i];
            if(dp[0][i]==1)ans++;
        }
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(m[i][j] == 0)continue;
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                ans += dp[i][j];
            }
        }
        // for(auto v:dp){
        //     for(auto a: v)cout<<a<<" ";cout<<endl;
        // }
        return (ans);
    }
};