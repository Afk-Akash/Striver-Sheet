//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int row = grid.size(), col = grid.back().size();
	    vector<vector<bool>> vis(row, vector<bool> (col, false));
	    queue<pair<int,int>> q;
	    for(int i = 0; i < row; i++){
	        for(int j = 0; j < col; j++){
	            if(grid[i][j] == 1){
	                q.push({i,j});
	                grid[i][j] = 0;
	                vis[i][j] = true;
	            }
	            
	        }
	    }
	    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	    int dis = 1;
	    while(q.size()){
	        int sz = q.size(); 
	        
	        while(sz--){
	            auto top = q.front();
	            q.pop();
	            
	            for(auto d : dir){
	                int x = top.first + d[0], y = top.second + d[1];
	                if(x >= 0 and x < row and y >= 0 and y < col and !vis[x][y] and grid[x][y] == 0){
	                    q.push({x,y});
	                    vis[x][y] = true;
	                    grid[x][y] = dis;
	                }
	            }
	        }
	        dis++;
	    }
	    
	    return grid;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends