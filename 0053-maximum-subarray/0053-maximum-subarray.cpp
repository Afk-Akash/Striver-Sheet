class Solution {
    int maxx = INT_MIN;
public:
    int fun(vector<int> &nums, int ind){
        if(ind < 0) return 0;
        int ans = nums[ind] + fun(nums, ind - 1);
        maxx = max(ans, maxx);
        return ans > 0 ? ans : 0;
    }
    int maxSubArray(vector<int>& nums) {
       int n = nums.size();
         fun(nums, n - 1);
        return maxx;
    }
};