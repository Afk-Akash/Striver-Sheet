//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	
	class disjointSet{
	    vector<int> parent, rank;
	    public:
	    disjointSet(int n){
	        rank.resize(n+1, 0);
	        parent.resize(n+1);
	        iota(parent.begin(), parent.end(), 0);
	    }
	    
	    int findParent(int node){
	        if(parent[node] == node) return node;
	        
	        return parent[node] = findParent(parent[node]);
	    }
	    
	    void unionByRank(int a, int b){
	        int parentA = findParent(a), parentB = findParent(b);
	        if(parentA == parentB) return ;
	        
	        if(rank[parentA] < rank[parentB]){
	            parent[parentA] = parentB;
	        }else if(rank[parentA] > rank[parentB]){
	            parent[parentB] = parentA;
	        }else{
	            parent[parentA] = parentB;
	            rank[b]++;
	        }
	    }
	};
public: 
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<tuple<int,int,int>> v;
        for(int i = 0; i < V; i++){
            for(auto ed : adj[i]){
                v.push_back(make_tuple(ed[1], i, ed[0]));
            }
        }
        int ans = 0;
        sort(v.begin(), v.end());
        disjointSet ds(V);
        // for(auto tup : v)cout<<get<1>(tup)<<" "<<get<2>(tup)<<endl;return 0;
        for(int i = 0; i < v.size(); i += 1){
            auto tup = v[i];
            int node1 = get<1>(tup), node2 = get<2>(tup);
            int p1 = ds.findParent(node1), p2 = ds.findParent(node2);
            // cout<<node1<<" "<<p1<<"   |||   "<<node2<<" "<<p2<<endl;
            if(p1 == p2)continue;
            ans += get<0>(tup);
            
            ds.unionByRank(node1, node2);
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends