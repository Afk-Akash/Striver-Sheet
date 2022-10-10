class Solution {
public:
    int largestRectangle(vector<int> &v){
        int n = v.size();
        vector<pair<int,int>> se(n);
        stack<int> st;
        se[0].first = -1; se[n-1].second = n;
        st.push(0);
        for(int i = 1; i < n; i++){
            while(st.size() and v[st.top()] >= v[i])st.pop();
            se[i].first = st.size() ? st.top() : -1;
            st.push(i);
        }
        while(st.size())st.pop();
        st.push(n-1);
        for(int i = n - 2; i >= 0; i--){
            while(st.size() and v[st.top()] >= v[i])st.pop();
            se[i].second = st.size() ? st.top() : n ;
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            // cout<<se[i].first<<"|"<<se[i].second<<endl;
            ans = max(ans, (se[i].second - se[i].first - 1)*v[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        // vector<int> vv = {3,1,3,2,2};
        // cout<<largestRectangle(vv);
        // return 0;
        int n = mat.size(), m = mat[0].size();
        vector<int> v(m,0);
        
        int ans = 0;
        for(int i = 0; i <n; i++){
            
            for(int j = 0; j < m; j++){
                if(mat[i][j]=='1') 
                    v[j] += 1;
                else 
                    v[j] = 0;
            }
            // for(auto a:v)cout<<a<<" ";cout<<endl;
            ans = max(ans, largestRectangle(v));
        }
        return ans;
    }
};