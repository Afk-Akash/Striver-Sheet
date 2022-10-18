class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return fun(nums, 0, nums.size() - 1);
    }
    
    int fun(vector<int> &nums, int l, int r){
        if(l > r) return  INT_MIN;
        int mid = (l + r)/2;
        int left = 0, right = 0;
        for( int curr = 0,  i = mid - 1; i >= l ; i--)
        {
            curr += nums[i];
            left = max(left, curr);
        }
        for(int curr = 0, i = mid + 1 ; i <= r; i++){
            curr += nums[i];
            right = max(right, curr);
        }
        
        int fromLeft = fun(nums, l, mid - 1);
        int fromRight = fun(nums, mid + 1, r);
        
        return max(left + right + nums[mid] , max(fromLeft, fromRight));
    }
};