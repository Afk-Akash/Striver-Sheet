#define ll long long
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = cost.size();
        ll total = accumulate(cost.begin(), cost.end(), 1LL*0);
        vector<pair<ll,ll>> v;
        for(int i = 0; i < n ; i++)v.push_back({nums[i], cost[i]});
        sort(v.begin(), v.end());
        
        ll mid = total/2, sum = 0 ;
        ll target=0;
        for(int i = 0; i < n; i++){
            sum += v[i].second;
            if(sum > mid){
                target = v[i].first;
                break;
            }
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(nums[i] - target) *1LL* cost[i];
        }
        return ans;
    }
};