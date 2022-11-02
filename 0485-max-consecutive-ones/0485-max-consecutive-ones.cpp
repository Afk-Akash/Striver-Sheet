class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        while( j < n ){
            if(!nums[j]){
                j++;
                i=j;
            }
            while(j < n and nums[j])j++;
            ans = max(j - i, ans);
        }
        return ans;
    }
};