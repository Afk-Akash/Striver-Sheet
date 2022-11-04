class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(0, nums, temp, ans);
        set<vector<int>> v;
        for(auto & a : ans){sort(a.begin(), a.end());v.insert(a);}
        ans.resize(0);
        for(auto & a : v)ans.push_back(a);
        return ans;
    }
    
    void fun(int ind, vector<int> & nums, vector<int>& temp, vector<vector<int>> & ans){
        if(ind == nums.size()){
            // sort(begin(temp), temp.end());
            ans.push_back(temp);
            return ;
        }
        
        fun(ind + 1, nums, temp, ans);
        temp.push_back(nums[ind]);
        fun(ind + 1, nums, temp, ans);
        temp.pop_back();
    }
};