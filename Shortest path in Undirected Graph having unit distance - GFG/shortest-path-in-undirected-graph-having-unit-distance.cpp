//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> ans(N,1e8);
        queue<int> q;
        
        vector<int> adj[N];
        for(auto & edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>vis(N,false);
        vis[src] = true;
        int k = 1;
        q.push(src);
        ans[src] = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto top = q.front();q.pop();
                for(auto & a : adj[top]){
                    if(vis[a])continue;
                    q.push(a);
                    vis[a] = true;
                    ans[a] = k;
                }
            }
            k++;
            
        }
        for(int i = 0; i < N; i++){
            if(ans[i] == 1e8)ans[i] = -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends