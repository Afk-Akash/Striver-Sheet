class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = nums[0], maxReach = nums[0], ans = 1;
        if(n == 1) return 0;
        
        for(int i = 1; i < n; i++){
            step--;
            maxReach = max(maxReach, i + nums[i]);
            // if(maxReach >= n - 1) return ans;
            if(step == 0 and i != n-1){
                ans++;
                step = maxReach - i;
            }
        }
        
        return ans;
    }
};