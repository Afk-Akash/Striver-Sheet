class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& t) {
        vector<int> neven,nodd,teven,todd;
        sort(nums.begin(), nums.end());
        sort(t.begin(), t.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] & 1) nodd.push_back(nums[i]);
            else neven.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(t[i] & 1) todd.push_back(t[i]);
            else teven.push_back(t[i]);
        }
        
        long long ans = 0;
        for(int i = 0; i < nodd.size(); i++){
            ans += abs(nodd[i] - todd[i])/2;
        }
        for(int i = 0; i < neven.size(); i++)ans += abs(neven[i] - teven[i])/2;
        
        return ans/2;
    }
};