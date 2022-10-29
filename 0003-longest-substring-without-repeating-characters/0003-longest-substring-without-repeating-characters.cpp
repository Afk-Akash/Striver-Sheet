class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        vector<int> ff(256,-1);
        int ans = 0;
        while(right < n){
            if(ff[s[right]] != -1){
                
                left = max(left, ff[s[right]]+1);
            }
            ff[s[right]] = right;
            ans = max(ans, right-left+1);
            right++;
        }
        
        return ans;
    }
};