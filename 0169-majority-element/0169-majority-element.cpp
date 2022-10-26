class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, val = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(cnt == 0){
                val = nums[i];
                cnt++;
            }
            else if(nums[i] == val)cnt++;
            else cnt--;
        }
        return val;
    }
};