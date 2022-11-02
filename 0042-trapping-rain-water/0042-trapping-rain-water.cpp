class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int ans = 0, lmax = 0, rmax = 0;
        while(i < j){
            // ans += max(min(lmax, rmax) - height[i],0);
            
            lmax = max(lmax, height[i]);
            rmax = max(rmax, height[j]);
            if(lmax < rmax){
                ans += max(min(lmax,rmax)-height[i], 0);
                i++;
            }
            else {
                ans += max(min(lmax, rmax)- height[j], 0);
                j--;
            }
        }
        return ans;
    }
};