//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    class disjointSet {
      public:
        vector<int> rank, parent, size;
        disjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int findParent(int n) {
            if (n == parent[n]) return n;

            return parent[n] = findParent(parent[n]);
        }

        void unionByRank(int a, int b) {
            int pA = findParent(a), pB = findParent(b);
            if (pA == pB) return ;

            if (rank[pA] < rank[pB]) {
                parent[pA] = pB;
            } else if (rank[pB] < rank[pA]) {
                parent[pB] = pA;
            } else {
                parent[pA] = pB;
                rank[pB]++;
            }
        }

        void unionBySize(int a, int b) {
            int pa = findParent(a), pb = findParent(b);
            if(pa == pb) return ;
            if (size[pa] < size[pb]) {
                parent[pa] = pb;
                size[pb] += size[pa];
            } else if (size[pb] < size[pa]) {
                parent[pb] = pa;
                size[pa] += size[pb];
            } else {
                parent[pb] = pa;
                size[pa] += size[pb];
            }
        }
    };
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0, -1}};
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid.back().size();
        disjointSet ds(row * col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]){
                    for(int k = 0; k < 4; k++){
                        int xx = i + dir[k][0], yy = j + dir[k][1];
                        if(xx >= 0 and xx < row and yy >= 0 and yy < col and grid[xx][yy]){
                            int node1 = xx*col + yy, node2 = i*col + j;
                            int pa = ds.findParent(node1), pb = ds.findParent(node2);
                            if(pa == pb)continue;
                            ds.unionBySize(node1, node2);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int area = 0;
                if(!grid[i][j]){
                    unordered_set<int> set;
                    for(auto d : dir){
                        int xx = i + d[0], yy = j + d[1];
                        if(xx < 0 or xx == row or yy < 0 or yy == col or !grid[xx][yy]) continue;
                        int node1 = xx*col + yy;
                        int pa = ds.findParent(node1);
                        set.insert(pa);
                    }
                    for(auto & a : set)area += ds.size[a];
                    ans = max(ans, area + 1);
                }
            }
        }
        return ans ? ans : row*col;
    }
};












//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends