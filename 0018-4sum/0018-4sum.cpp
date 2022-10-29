class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                long long target = 1LL*k - nums[i] - nums[j];
                
                int left = j+1, right = n - 1;
                while(left < right){
                    int sum = nums[left] + nums[right];
                    if(sum < target)left++;
                    else if(sum > target)right--;
                    else{
                        vector<int> v(4);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[left];
                        v[3] = nums[right];
                        
                        ans.push_back(v);
                        while(left < right && v[2] == nums[left]  )left++;
                        while( right > left && v[3] == nums[right] )right--;
                    }
                }
                cout<<"a";
                while(j < n-1 and nums[j] == nums[j+1] )j++;
                cout<<"a";
            }
            while(i < n-1 && nums[i] == nums[i+1]  )i++;
        }
        // vector<vector<int>> res;
        // for(auto & a: ans)res.push_back(a);
        return ans;
    }
};