class Solution {
    int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> se(n);
        stack<int> st;
        for(int i = 0; i < arr.size(); i++){
            while(st.size() and arr[i] < arr[st.top()])st.pop();
            se[i].first = st.size() ? st.top() : -1;
            st.push(i);
        }
        while(st.size())st.pop();
        
        for(int i = n - 1; i >= 0; i--){
            while(st.size() and arr[i] <= arr[st.top()])st.pop();
            se[i].second = st.size() ? st.top() : n;
            st.push(i);
        }
        // for(auto & a : se){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = (ans % mod + 1LL*(i - se[i].first)*(se[i].second - i)*arr[i]%mod)%mod;
        }
        return ans;
    }
};