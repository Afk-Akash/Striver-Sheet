class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto & a : nums)set.insert(a);
        int n = nums.size();
        if(n <= 1) return n;
        int ans = 0;
        for(auto & a : set){
            int prev = a - 1, next = a+1;
            while(set.count(prev))set.erase(prev--);
            while(set.count(next))set.erase(next++);
            ans = max(ans, next - prev - 1);
        }
        return ans;
    }
};