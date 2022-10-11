class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            int start = i, end = i;
                while(start >= 0 and s[start] == s[end] and end < n){
                    start--;
                    end++;
                }
            if(end-start-1 > ans.size())ans = s.substr(start+1, end-start-1);

                start = i;end = i+1;
                while(start >= 0 and s[start] == s[end] and end < n){
                    start--;
                    end++;
                }
            if(end-start-1 > ans.size())ans = s.substr(start+1, end-start-1);
            if(ans.size() == n)return ans;
        }
        return ans;
    }
};