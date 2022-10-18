class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(n, vector<int> (2,0));
        int ans;
        v[0][0] = v[0][1] = ans = nums[0];
        
        for(int i = 1; i < n; i++){
            if(nums[i] < 0)swap(v[i-1][0], v[i-1][1]);
            
            v[i][0] = min(nums[i], nums[i] * v[i-1][0]);
            v[i][1] = max(nums[i], nums[i] * v[i-1][1]);
            
            ans = max(ans, v[i][1]);
        }
        
        return ans;
    }
};