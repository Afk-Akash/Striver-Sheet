class Solution {
public:
    string robotWithString(string s) {
        stack< char > st;
        map<char,int> mp;
        for(auto &c: s)mp[c]++;
        int n = s.size();
        string ans = "";
        
        for(int i = 0; i < n; i++){
            st.push(s[i]);
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            // cout<<st.top()<<" "<<mp.begin()-> first<<mp.begin()->second<<endl;
            while(st.size() and st.top() <= mp.begin() -> first){
                
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