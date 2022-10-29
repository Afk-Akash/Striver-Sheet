class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        unordered_set<char> set;
        int ans = 0;
        while(right < n){
            while(set.count(s[right])){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            ans = max(ans, right-left+1);
            right++;
        }
        
        return ans;
    }
};