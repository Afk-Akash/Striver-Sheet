class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while(j < n){
            nums[i] = nums[j];
            while(j < n-1 and nums[j] == nums[j+1])j++;
            j++;
            i++;
        }
        return i;
    }
};