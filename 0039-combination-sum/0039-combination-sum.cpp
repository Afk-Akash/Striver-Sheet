class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int> ds;
        fun(0, candidates, target, ds, ans);
        return ans;
    }
    
    void fun(int ind, vector<int> & candidates, int & k , vector<int> & ds, vector<vector<int>> & ans){
        if(ind == candidates.size()){
            if(k == 0) ans.push_back(ds);
            return ;
        }
        
        fun(ind + 1, candidates, k, ds, ans);
        if(candidates[ind] <= k){
            ds.push_back(candidates[ind]);
            k -= candidates[ind];
            fun(ind, candidates, k , ds, ans);
            ds.pop_back();
            k += candidates[ind];
        }
    }
};