//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> stack;
        for(int i = 0; i < V; i++){
            if(!vis[i])dfs(i, adj, stack, vis);
        }
        
        vector<int> revGraph[V];
        for(int i = 0; i < V; i++){
            for(auto ed : adj[i])revGraph[ed].push_back(i);
        }
        vis = vector<bool>(V, false);
        int cnt = 0;
        for(int i = V-1; i >= 0 ; i--){
            int node = stack[i];
            if(!vis[node]){
                dfs(node, revGraph, vis);
                cnt++;
            }
        }
        return cnt;
    }
    
    void dfs(int node, vector<int> adj[], vector<bool> &vis){
        vis[node] = true;
        for(auto ed : adj[node]){
            if(vis[ed]) continue;
            dfs(ed, adj, vis);
        }
    }
    
    void dfs(int node, vector<int> adj[], vector<int> &st, vector<bool> &vis){
        vis[node] = true;
        for(auto ed : adj[node]){
            if(vis[ed]) continue;
            dfs(ed, adj, st, vis);
        }
        st.push_back(node);
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends