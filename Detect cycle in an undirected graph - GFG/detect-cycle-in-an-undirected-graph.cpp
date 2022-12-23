//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++){
            if(vis[i] == false){
                vis[i] = true;
                if(dfs(i, adj, vis, -1)) return true;
            }
        }
        return false;
        
    }
    
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, int pre){
        // if(vis[node] == true and pre == node);
        
        for(auto & a : adj[node]){
            if(vis[a] == true and a == pre)continue;
            if(vis[a] == true) return true;
            vis[a] = true;
            if(dfs(a, adj, vis, node)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends