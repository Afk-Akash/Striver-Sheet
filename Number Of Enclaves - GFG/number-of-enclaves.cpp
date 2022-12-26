//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int dir[4][2] = {{-1,0},{1,0}, {0,1},{0,-1}};
  public:
    
    void dfs(int x, int y, vector<vector<int>> &mat){
        // cout<<1<<endl;
        mat[x][y] = 0;
        for(auto & d : dir){
            int i = x + d[0], j = y + d[1];
            if(i < mat.size() and i >= 0 and j < mat.back().size() and j >= 0 and mat[i][j] == 1){
                dfs(i,j, mat);
                // mat[i][j] = 0;
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int row = grid.size(), col = grid.back().size();
        for(int i = 0; i < row; i++){
            if(grid[i][0] == 1)dfs(i,0,grid);
            if(grid[i][col-1] == 1)dfs(i,col-1, grid);
        }
        for(int i = 0; i < col; i++){
            if(grid[0][i] == 1) dfs(0, i, grid);
            if(grid[row-1][i] == 1)dfs(row-1, i, grid);
        }
        int ans = 0;
        for(auto & rw : grid){
            for(auto &land : rw)if(land)ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends