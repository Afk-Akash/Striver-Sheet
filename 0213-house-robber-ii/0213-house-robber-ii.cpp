class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        if(n > 1) dp[1] = max(dp[0], nums[1]);
        else return nums[0];
        
        for(int ii = 2; ii < n - 1; ii++){
            auto i = ii;
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int ans = dp[n-2];
        dp.resize(n, 0);
        if(n > 2){
            dp[1] = nums[1];
            dp[2] = max(nums[2], dp[1]);
        }
        
        for(int i = 3; i < n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        ans = max(ans, dp[n-1]);
        
        return ans;
    }
};