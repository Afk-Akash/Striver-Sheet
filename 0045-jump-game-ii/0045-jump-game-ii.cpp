class Solution {
public:
    int fun(int ind, vector<int> &nums, vector<int> &dp){
        if(ind >= nums.size() - 1) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        int ans = 1e7;
        for(int i = 1; i <= nums[ind]; i++){
            int jump = 1 + fun(ind + i, nums, dp);
            ans = min(ans, jump);
        }
        return dp[ind] = ans;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        // return fun(0, nums, dp);
        
        for(int i = n - 2; i >= 0; i--){
            int k = nums[i];
            int mini = 1e4;
            
            for(int j = i+1; j < min(i+k+1,n); j++){
                mini = min(dp[j] , mini);
            }
            
            dp[i] = mini+1;
        }
        return dp[0];
    }
};