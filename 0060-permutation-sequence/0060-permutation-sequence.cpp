class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        int fact = 1;
        vector<char> nums;
        for(int i = 1; i < n; i++){
            fact = fact * i;
            nums.push_back(i + '0');
        } 
        nums.push_back(n+'0');
        k--;
        while(true){
            int ind = k / fact;
            ans += nums[ind];
            nums.erase(nums.begin() + ind);
            if(nums.size()){
                k = k % fact;
                fact /= nums.size();
            }else break;
        }
        return ans;
    }
};