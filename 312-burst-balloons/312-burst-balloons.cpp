class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n-1, 0));
        // return fun(1, n-2, nums, dp);
        for(int start = n - 2; start >= 1; start--){
            for(int end = start; end <= n- 2; end++){
                int maxi = 0;
                for(int i = start; i <= end; i++){
                    int coins = nums[start -1] * nums[i] * nums[end + 1] + dp[start][i - 1]+ dp[i + 1][end];
                    maxi = max(maxi, coins);
                }
                dp[start][end] = maxi;
            }
        }
        return dp[1][n-2];

    }
    
    int fun(int start, int end, vector<int> &nums, vector<vector<int>> &dp){
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int maxi = 0;
        for(int i = start; i <= end; i++){
            int coins = nums[start-1] * nums[i] * nums[end + 1] + fun(start, i - 1, nums, dp) + fun(i + 1, end, nums, dp);

            maxi = max(maxi, coins);
        }
        return dp[start][end] = maxi;
    }
};