class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> post(n) , pre(n);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            pre[i] = cnt;
            cnt = max(cnt, height[i]);
        }
        cnt = 0;
        for(int i = n-1; i >= 0; i--){
            post[i] = cnt;
            cnt = max(cnt, height[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int mini = min(pre[i], post[i]);
            ans += max(mini - height[i], 0);
        }
        return ans;
    }
};