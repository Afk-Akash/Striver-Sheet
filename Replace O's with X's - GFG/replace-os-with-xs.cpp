//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    bool isvalid(int i, int j, int row, int col){
        return i >= 0 and i < row and j >= 0 and j < col;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        int row = mat.size(), col = mat.back().size();
        vector<vector<bool>> vis(row, vector<bool>(col,false));
        vector<pair<int,int>> v;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 'O')v.push_back({i,j});
            }
        }
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        n = v.size();
        for(auto i = 0; i < n; i++){
            auto p = v[i];
            if(!vis[p.first][p.second]){
                vis[p.first][p.second] = true;
                if(p.first == 0 or p.first == row-1 or p.second == 0 or p.second == col - 1) continue;
                // cout<<p.first<<" "<<p.second<<" <- "<<endl;
                queue<pair<int,int>> q;
                q.push({p.first, p.second});
                bool flag = true;
                while(q.size()){
                    auto top = q.front();
                    q.pop();
                    
                    for(auto & d : dir){
                        int x = top.first + d[0], y = top.second + d[1];
                        if(x > 0 and x < row-1 and y > 0 and y < col-1 and !vis[x][y] and mat[x][y] == 'O'){
                            q.push({x,y});
                            vis[x][y] = true;
                        }
                        
                        if(isvalid(x,y,row,col) and (x == 0 or y == 0 or x == row - 1 or y == col - 1) and mat[x][y] == 'O'){
                            flag = false;
                            // cout<<x<<" "<<y<<endl;
                            // break;
                        }
                    }
                    // if(!flag)break;
                }
                if(flag)v.push_back({p.first,p.second});
            }
        }//cout<<n<<endl<<v.size();
        // cout<<n<<" "<<v.size()<<endl;
        for(int i = n; i < v.size(); i++){
            auto p = v[i];
            // cout<<p.first<<" "<<p.second<<endl;
            queue<pair<int,int>> q;
            q.push({p.first, p.second});
            vis[p.first][p.second] = true;
            mat[p.first][p.second] = 'X';
            while(q.size()){
                auto top = q.front();
                q.pop();
                for(auto & d : dir){
                    int x = top.first + d[0], y = top.second + d[1];
                    if(isvalid(x,y,row,col) and mat[x][y] == 'O'){
                        mat[x][y] = 'X';
                        q.push({x,y});
                    }
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends