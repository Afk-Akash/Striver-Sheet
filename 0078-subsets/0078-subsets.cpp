class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int size = ans.size();
            for(int j = 0; j < size; j++){
                auto t = ans[j];
                t.push_back(nums[i]);
                ans.push_back(t);
            }
        }
        return ans;
    }
};