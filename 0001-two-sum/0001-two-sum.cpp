class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> set;
        for(int i = 0; i < nums.size(); i++){
            if(set.find(target-nums[i]) != set.end())return {i, set[target-nums[i]]};
            set[nums[i]] = i;
        }
        return {};
    }
};