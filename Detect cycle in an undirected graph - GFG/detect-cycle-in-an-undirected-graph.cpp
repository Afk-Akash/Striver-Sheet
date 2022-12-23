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
                queue<pair<int,int>> q;
                q.push({i,-1});
                vis[i] = true;
                while(q.size()){
                    auto top = q.front();
                    q.pop();
                    for(auto & a : adj[top.first]){
                        if(vis[a] == 1 and top.second == a)continue;
                        if(vis[a]) return true;
                        q.push({a, top.first});
                        vis[a] = true;
                    }
                }
            }
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