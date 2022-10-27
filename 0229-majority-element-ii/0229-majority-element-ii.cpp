class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int a = INT_MAX, b = INT_MAX, na = 0, nb = 0;
        for(int i = 0; i < n; i++){
            
            if(nums[i] == a)na++;
            else if(nums[i] == b)nb++;
            else if(na == 0){
                a = nums[i];
                na = 1;
            }
            else if( nb == 0){
                b = nums[i];
                nb = 1;
            }
            else {
                na--;
                nb--;
            }
        }
        na = 0, nb = 0;
        for(auto & ak: nums){
            if(ak == a)na++;
            if(ak == b)nb++;
        }
        if(na > n/3 and nb > n/3) return {a,b};
        if (na > n/3) return  {a} ;
        
        if(nb > n/3) return {b};
        return {};
    }
};