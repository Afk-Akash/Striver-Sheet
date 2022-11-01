class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int k = 0 - nums[i];
            int left = i + 1, right = n - 1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum < k)left++;
                else if(sum > k)right--;
                else{
                    vector<int> v(3);
                    v[0] = nums[i];
                    v[1] = nums[left];
                    v[2] = nums[right];
                    
                    ans.push_back(v);
                    while(left < right and nums[left] == nums[left+1])left++;
                    while(left < right and nums[right] == nums[right-1])right--;
                    left++;
                    right--;
                }
            }
            while(i+1 < n and nums[i] == nums[i+1])i++;
        }
        return ans;
    }
};