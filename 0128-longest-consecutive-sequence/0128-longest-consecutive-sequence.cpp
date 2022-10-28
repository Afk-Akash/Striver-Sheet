class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int & a : nums){
            if(mp[a])continue;
            
            int k = mp[a-1] + mp[a+1] + 1;
            mp[a - mp[a-1]] = k;
            mp[a + mp[a+1]] = k;
            mp[a] = k;
            ans = max(ans,k);
        }
        return ans;
    }
};