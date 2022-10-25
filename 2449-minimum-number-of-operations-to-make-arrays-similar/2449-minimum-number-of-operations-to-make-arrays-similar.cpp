class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& t) {
        vector<int> num[2], tar[2];
        sort(nums.begin(), nums.end());
        sort(t.begin(), t.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            num[nums[i]%2].push_back(nums[i]);
            tar[t[i]%2].push_back(t[i]);
        }
        
        return (fun(num[0],tar[0]) + fun(num[1],tar[1]))/2;
        
    }
    
    long long fun(vector<int> &v, vector<int> &t){
        int n = t.size();
        long long ans = 0;
        for(int i =0; i < n; i++){
            ans += abs(v[i] - t[i])/2;
        }
        return ans;
    }
};