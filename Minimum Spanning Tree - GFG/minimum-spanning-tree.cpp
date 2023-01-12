//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue< vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        vector<bool> vis(V,false);
        int mst = 0;
        
        pq.push({0,V-1,-1});
        while(pq.size()){
            auto t = pq.top();
            pq.pop();
            int cost = t[0], node = t[1], parent = t[2];
            if(vis[node])continue;
            mst += cost;
            vis[node] = true;
            for(auto edge : adj[node]){
                int upcomingNode = edge[0], wt = edge[1];
                if(vis[upcomingNode]) continue;
                pq.push({wt, upcomingNode, node});
            }
        }
        return mst;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends