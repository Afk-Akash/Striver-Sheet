class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = n*m-1;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(mat[mid/m][mid%m] < k)l = mid + 1;
            else r = mid - 1;
        }
        return (l < n*m  and mat[l/m][l%m] == k);
    }
};