class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        // set<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        for(auto  a : candidates)cout<<a<<",";
        fun(0, candidates, ds, v, target);
        // for(auto & a : ans)v.push_back(a);
        return v;
    }
    
    void fun(int ind, vector<int> &nums, vector<int> ds, vector<vector<int>> &ans, int  k){
        if(ind == nums.size()){
            if(!k)ans.push_back(ds);
            return;
        }
        //1,1,2,5,6,7,10
        
        if(nums[ind] <= k){
            ds.push_back(nums[ind]);
            fun(ind + 1, nums, ds, ans, k - nums[ind]);
            ds.pop_back();
        }
        ind++;
        while(ind < nums.size() and nums[ind-1] == nums[ind])ind++;

        fun(ind, nums, ds, ans, k);
    }
};