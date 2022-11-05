class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans = {{}};
        int size = 0;
        for(int i = 0; i < n; i++){
            int start = i > 0 and nums[i] == nums[i-1] ? size : 0 ;
            size = ans.size();
            for(int j = start; j < size; j++){
                auto t = ans[j];
                t.push_back(nums[i]);
                ans.push_back(t);
            }
        }
        return ans;
    }
};