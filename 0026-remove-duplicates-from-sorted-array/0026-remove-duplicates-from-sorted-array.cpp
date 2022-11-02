class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(1,0);
        for(int i = 1; i < n; i++){
            if(nums[v.back()] != nums[i])v.push_back(i);
        }
        n = v.size();
        for(int i = 0; i < n; i++){
            swap(nums[i], nums[v[i]]);
        }
        return n;
    }
};