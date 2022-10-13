class Solution {
    int mod = 1000000007;
public:
    int sumSubarrayMins(vector<int>& v) {
        int n = v.size();
        vector<int> nse(n), pse;
        
        stack<int> st;
        pse.push_back(-1);
        st.push(0);
        for(int i = 1; i < n; i++){
            while(st.size() and v[st.top()] > v[i])st.pop();
            pse.push_back(st.size() ? st.top() : -1);
            st.push(i);
        }
        while(st.size())st.pop();
        nse[n-1] = n;
        st.push(n-1);
        for(int i = n - 2; i >= 0; i--){
            while(st.size() and v[st.top()] >= v[i])st.pop(); // = to sign because 1 time we have to cover
                                                                //whole list [7,5,9,5] for [7,5],[5],[5,9]
            nse[i] = st.size() ? st.top() : n;                  //[7,5,9] min is 5 and also for [9,5],[5] min 
                                                                //is 5 but we are not calculting for[7,5,9,5]and
            st.push(i);                                         //[5,9,5] that is why we have to check if there
        }                                                       //is equal value then also we count it in distance
        // for(auto a : pse)cout<<a<<" ";cout<<endl;
        // for(auto a : nse)cout<<a<<" ";
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += (1LL*v[i] * (nse[i] - i) * (i - pse[i]))%1000000007;
        }
        return ans%mod;
    }
};