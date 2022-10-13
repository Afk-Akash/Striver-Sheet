class Solution {
    int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> dp(n);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            while(st.size() and arr[st.top()] > arr[i])st.pop();
            
            int prev = st.size() ? st.top() : -1;
            dp[i] = arr[i] * (i - prev);
            if(prev != -1)dp[i] += dp[prev];
            
            ans = (ans + dp[i])%mod;
            st.push(i);
            
        }
        return ans;
    }
};