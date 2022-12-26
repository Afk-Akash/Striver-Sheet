//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
   int dir[4][2] = {{-1,0},{1,0}, {0,1},{0,-1}};
   
   bool isvalid(int i, int j, int x, int y){
       return i < x and j < y and i >= 0 and j >= 0;
   }
   pair<int,int> sub(pair<int,int> a, pair<int,int> b){
       pair<int,int> c;
       c.first = a.first - b.first;
       c.second = a.second - b.second;
       return c;
   }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> set;
        int ans = 0;
        int row = grid.size(), col = grid.back().size();
        for(int  i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vector<pair<int,int>> vv;
                    pair<int,int> base = {i,j};
                    
                    while(q.size()){
                        int sz = q.size();
                        while(sz--){
                            auto top = q.front();
                            vv.push_back(sub(top,base));
                            q.pop();
                            for(int k = 0; k < 4; k++){
                                auto d = dir[k];
                                int x = top.first + d[0], y = top.second + d[1];
                                if(isvalid(x, y, row, col) and grid[x][y] == 1){
                                    grid[x][y] = 0;
                                    q.push({x,y});

                                }
                            }
                        }
                    }
                    if(set.find(vv) == set.end())ans++;
                    set.insert(vv);
                }
            }
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends