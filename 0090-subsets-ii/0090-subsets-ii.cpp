class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        fun(0, nums, temp, ans);
        vector<vector<int>> v;
        for(auto & a : ans)v.push_back(a);
        return v;
    }
    
    void fun(int ind, vector<int> & nums, vector<int> temp, set<vector<int>> & ans){
        if(ind == nums.size()){
            sort(begin(temp), temp.end());
            ans.insert(temp);
            return ;
        }
        
        fun(ind + 1, nums, temp, ans);
        temp.push_back(nums[ind]);
        fun(ind + 1, nums, temp, ans);
        temp.pop_back();
    }
};