class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> v(n,1);
        
        for(int i = m-2; i >= 0; i--){
            vector<int> vv(n,1);
            for(int j = n-2; j >= 0; j--){
                vv[j] = v[j] + vv[j+1];
            }
            v = vv;
        }
        return v[0];
    }
};