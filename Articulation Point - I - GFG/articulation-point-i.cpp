//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 0;
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int disc[V], mini[V];
        vector<int> ans;
        vector<bool> vis(V, false);
        set<int> set;
        dfs(0, -1, adj, disc, mini, vis, set);
        for(auto e : set)ans.push_back(e);
        if(ans.size()) return ans;
        return {-1};
    }
    void dfs(int node, int parent, vector<int> adj[], int disc[], int mini[], vector<bool> &vis, set<int> &set){
        vis[node] = true;
        disc[node] = mini[node] = timer;
        timer++;
        int child = 0;
        for(auto ed : adj[node]){
            if(ed == parent) continue;
            if(!vis[ed]){
                dfs(ed, node, adj, disc, mini, vis, set);
                mini[node] = min(mini[node], mini[ed]);
                if(mini[ed] >= disc[node] and parent != -1)set.insert(node);
                child++;
            }else
                mini[node]  = min(mini[node], disc[ed]);
        }
        if(child > 1 and parent == -1)set.insert(node);
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends