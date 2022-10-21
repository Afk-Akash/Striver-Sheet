class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        for(auto &a: nums){if(a==0)r++;
        if(a==1)w++;
        if(a==2)b++;}
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(r){nums[i] = 0;r--;}
            else if(w){nums[i] = 1;w--;}
            else if(b){nums[i] = 2;b--;}

        }
    }
};