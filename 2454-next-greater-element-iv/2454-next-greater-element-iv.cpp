class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        if(n==1) return {-1};
        if(n == 2) return {-1,-1};
        stack<int> st;
        vector<vector<int>> mp(n);
        

        for(int i = n-1; i >= 0; i--){
            while(st.size() and nums[st.top()] <= nums[i]){
                // cout<<"ak "<<i<<endl;
                mp[i].push_back(st.top());
                st.pop();
            }
            if(st.empty()){
                st.push(i);
                continue;
            }
            bool flag = false;
            for(int j = 0; j < mp[st.top()].size(); j++){
                if(nums[mp[st.top()][j]] > nums[i]){
                    ans[i] = nums[mp[st.top()][j]];
                    flag = true;
                    break;
                }
                
            }
            if(flag == false){
                if(st.size() >= 2){
                    int top = st.top();
                    st.pop();
                    ans[i] = nums[st.top()];
                    st.push(top);
                }
                
            }
            st.push(i);
        }
       
        return ans;
    }
};