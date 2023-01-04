//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V,INT_MAX);
        ans[S] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<pair<int,int>> set;
        set.insert({0,S});
        pq.push({0,S});
        
        while(set.size()){
            pair<int,int> top = *set.begin();
            set.erase(top);
            int cost = top.first;
            for(auto & edge : adj[top.second]){
                int upcomingNode = edge[0], price = edge[1];
                 if(ans[upcomingNode] > cost + price){
                     if(ans[upcomingNode] != INT_MAX) set.erase({ans[upcomingNode], upcomingNode});
                     ans[upcomingNode] = cost + price;
                     
                     set.insert({ans[upcomingNode], upcomingNode});
                 }
                
            }
        }
        return ans;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends