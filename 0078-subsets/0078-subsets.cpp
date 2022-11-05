class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        fun(0, nums, ds, ans);
        return ans;
    }
    
    void fun(int ind, vector<int> & nums, vector<int> & ds, vector<vector<int> > &ans){
        if(ind == nums.size()){
            ans.push_back(ds);
            return ;
        }
        fun(ind + 1, nums, ds, ans);
        ds.push_back(nums[ind]);
        fun(ind + 1, nums, ds, ans);
        ds.pop_back();
    }
};