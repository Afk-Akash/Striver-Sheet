class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(nums, 0, ans);
        return ans;
    }
    
    void fun(vector<int> &nums, int ind, vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = ind; i < nums.size(); i++){
            swap(nums[i], nums[ind]);
            fun(nums, ind + 1, ans);
            swap(nums[i], nums[ind]);
        }
    }
};