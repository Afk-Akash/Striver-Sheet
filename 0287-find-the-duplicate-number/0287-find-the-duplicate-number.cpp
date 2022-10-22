class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0, x = 0, y = 0;
        for(int bit = 0; bit < 31; bit++){
            x = 0, y = 0;
            for(int i = 0; i < nums.size(); i++ ){
                if(nums[i] & (1 << bit))x++;
                if((i) & (1 << bit))y++;
            }
            if(x > y) ans |= (1 << bit);
        }
        return ans;
    }
};