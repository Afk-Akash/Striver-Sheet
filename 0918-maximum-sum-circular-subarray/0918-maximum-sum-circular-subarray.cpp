class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = 0, mini = INT_MAX, neg_sum = 0, total = 0;
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) flag = false; 
            sum += nums[i];
            ans = max(ans,sum);
            if(sum < 0)sum = 0;
            neg_sum += nums[i];
            if(neg_sum > 0)neg_sum = 0;
            mini = min(mini, neg_sum);
        }
        total = accumulate(nums.begin()+1, nums.end(), nums[0]);
        if(flag) return *max_element(nums.begin(), nums.end());
        return max(ans, total - mini);
        
    }
};