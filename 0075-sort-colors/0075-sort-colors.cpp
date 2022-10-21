class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size()-1, k = 0;
        for(int i = 0; i <= n; i++){
            while(nums[i] == 2 and i < n)swap(nums[i], nums[n--]);
            while(nums[i] == 0 and i > k)swap(nums[i], nums[k++]);
        }
    }
};