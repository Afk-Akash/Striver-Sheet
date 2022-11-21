class Solution {
public:
    void sortColors(vector<int>& nums) {
        reverse(nums.begin() , nums.end());
        sort(nums.begin() , nums.end());
        
    }
};