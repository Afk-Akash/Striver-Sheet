class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return fun(nums, 0, nums.size()-1);
    }
    
    int fun(vector<int> &nums, int l, int r){
        if(l== r) return nums[l];
        
        int mid = (l+r)/2;
        int left = fun(nums, l, mid);
        int right = fun(nums, mid+1, r);
        
        return freq(nums,l,r,left,right) ? left : right;
    }
    
    bool freq(vector<int> &v,int l, int r, int j, int k){
        int cnt = 0,cc=0;
        for(int i = l; i <= r; i++){
            int a = v[i];
            if(a==k)cnt++;
            if(a==j)cc++;
        }
        return cc>cnt;
    }
};