class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                for(int j = i+1; j < n; j++){
                    if(nums[i] >= nums[j]){
                        swap(nums[i], nums[j-1]);
                        sort(nums.begin()+i+1, nums.end());
                        return ;
                    }
                }
                swap(nums[i], nums[n-1]);
                sort(nums.begin()+i+1,nums.end());
                return ;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};