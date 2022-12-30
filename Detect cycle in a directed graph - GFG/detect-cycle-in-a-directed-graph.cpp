//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> in(V,0);
        for(int  i = 0; i < V; i++){
            for(auto & edge  : adj[i])in[edge]++;
        }
        queue<int> q;
        for(int ii = 0; ii < V; ii++)if(!in[ii])q.push(ii);
        int k = 1;
        vector<int> topo;
        while(q.size()){
            auto top = q.front();
            q.pop();
            k++;
            topo.push_back(top);
            for(auto & edge : adj[top]){
                in[edge]--;
                if(!in[edge])q.push(edge);
            }
        }
        return k !
        return topo.size() != V;
        for(auto & a : in)if(a)return 1;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends