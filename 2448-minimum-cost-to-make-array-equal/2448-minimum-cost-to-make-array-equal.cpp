class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = 1, r = 1e6, n = nums.size();
        long long ans = 922337203685477580;
        while( l  <= r ){
            int mid1 = (l*2+r)/3, mid2 = (2*r+l)/3;
            long long t1 = 0, t2 = 0;
            
            for(int i = 0; i < n; i++){
                
                int diff1 = abs(mid1 - nums[i]);
                int diff2 = abs(mid2-nums[i]);
                t1 += 1LL*diff1 * cost[i];
                t2 += 1LL*diff2*cost[i];
            }
            ans = min(ans, min(t1,t2));
            // cout<<l<<" "<<r<<endl;
            if(t1 < t2)r = mid2-1;
            else l = mid1+1;
        }
        long long t = LLONG_MAX;
        // int mid = (l+r)/2;
        // for(int i = 0; i < n; i++){
        //     int diff = abs(nums[i] - mid);
        //     t += 1LL * diff * cost[i];
        // }
        return min(ans, t);
    }
};