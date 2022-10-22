class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;
        for(int i = 0; i < n; i++){
            if(set.find(nums[i]) != set.end())return nums[i];
            set.insert(nums[i]);
        }
        return -1;
    }
};