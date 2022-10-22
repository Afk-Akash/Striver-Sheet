class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size(), mid;
        while(l <= r){
            mid = (l+r) >> 1;
            int cnt = 0;
            for(auto &a : nums)if(a <= mid)cnt++;
            
            if(cnt <= mid)l = mid + 1;
            else r = mid - 1;
            
        }
        return l;
    }
};