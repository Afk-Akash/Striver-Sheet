class Solution {
public:
    char low (vector<int> &v){
        for(int i = 0; i <= 25; i++){
            if(v[i]!=0)return i + 'a';
        }
        return 'a';
    }
    string robotWithString(string s) {
        stack< char > st;
        vector<int> freq(26,0);
        for(auto &c: s)freq[c-'a']++;
        int n = s.size();
        string ans = "";
        
        for(int i = 0; i < n; i++){
            st.push(s[i]);
            freq[s[i]-'a']--;
            while(st.size() and st.top() <= low(freq)){
                
                ans += st.top();
                st.pop();
            }
            
        }
        while(st.size()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};