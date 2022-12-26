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
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<vector<pair<int,int>>>> set;
        int ans = 0;
        int row = grid.size(), col = grid.back().size();
        for(int  i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vector<vector<pair<int,int>>> vv;
                    
                    while(q.size()){
                        int sz = q.size();
                        vector<pair<int,int>> v;
                        while(sz--){
                            auto top = q.front();
                            q.pop();
                            for(int k = 0; k < 4; k++){
                                auto d = dir[k];
                                int x = top.first + d[0], y = top.second + d[1];
                                if(isvalid(x, y, row, col) and grid[x][y] == 1){
                                    grid[x][y] = 0;
                                    q.push({x,y});
                                    v.push_back({sz,k});
                                }
                            }
                        }
                        vv.push_back(v);
                    }
                    if(set.find(vv) == set.end())ans++;
                    set.insert(vv);
                }
            }
        }
        // for(auto &vvp : set){
        //     for(auto &vp : vvp){
        //         for(auto &p : vp){cout<<p.first<<" "<<p.second<<"    ";}cout<<endl;
        //     }cout<<1<<endl;
        // }
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