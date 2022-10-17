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
        vector<int> dp(n+1, -1);
        return fun(0, nums, dp);
    }
};