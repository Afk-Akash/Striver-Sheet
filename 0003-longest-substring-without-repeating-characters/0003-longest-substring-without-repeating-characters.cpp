class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        vector<int> ff(256,0);
        int ans = 0;
        while(right < n){
            while(ff[s[right]]){
                ff[s[left]]--;
                left++;
            }
            ff[s[right]]++;
            ans = max(ans, right-left+1);
            right++;
        }
        
        return ans;
    }
};