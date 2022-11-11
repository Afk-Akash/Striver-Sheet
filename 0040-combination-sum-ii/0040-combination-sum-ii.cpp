class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        fun(0, candidates, target, ds, ans);
        return ans;
    }
    
    void fun(int ind, vector<int>& v, int k, vector<int> &ds, vector<vector<int>> & ans){
        if(k == 0) {
            ans.push_back(ds);
            return ;
        }
        if(ind == v.size())return ;
        
        for(int i = ind; i < v.size(); i++){
            if(i != ind and v[i-1] == v[i])continue;
            if(v[i] > k) break;
            ds.push_back(v[i]);
            fun(i+1, v, k - v[i], ds, ans);
            ds.pop_back();
        }
    }
};