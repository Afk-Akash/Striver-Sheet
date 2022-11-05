class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_set<string> set;
        vector<vector<int>> ans;
        for(int i = 0; i < (1 << n); i++){
            string str = "";
            vector<int> t;
            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    t.push_back(nums[j]);
                    str.push_back(nums[j] + '0');
                }
                
            }
            if(!set.count(str)){
                ans.push_back(t);
                set.insert(str);
            }
        }
        return ans;
    }
};