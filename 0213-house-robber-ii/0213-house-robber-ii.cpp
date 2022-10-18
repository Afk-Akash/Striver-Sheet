class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        if(n > 1) dp[1] = max(dp[0], nums[1]);
        
        for(int ii = 2; ii < n - 1; ii++){
            auto i = ii;
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int ans = dp[n-2];
        vector<int> dpp(n, 0);
        if(n > 2){
            dpp[1] = nums[1];
            dpp[2] = max(nums[2], dpp[1]);
        }
        
        for(int i = 3; i < n; i++){
            dpp[i] = max(dpp[i-1], dpp[i-2] + nums[i]);
        }
        ans = max(ans, dpp[n-1]);
        
        return ans;
    }
};