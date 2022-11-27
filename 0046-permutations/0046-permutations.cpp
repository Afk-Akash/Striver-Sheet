class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        fun(nums, 0, ans);
        return ans;
    }
    
    void fun(vector<int> & nums, int i, vector<vector<int>> & ans){
        if(i == nums.size() ){
            ans.push_back(nums);
            return ;
        }
        for(int ind = i; ind < nums.size(); ind++){
            swap(nums[i], nums[ind]);
            fun(nums, i+1, ans);
            swap(nums[i], nums[ind]);
        }
    }
};