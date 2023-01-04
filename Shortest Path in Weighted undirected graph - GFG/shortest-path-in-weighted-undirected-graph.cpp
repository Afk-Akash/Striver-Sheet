//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // cout<<n;//return {};
        vector<pair<int,int>> adj[n+1];
        for(auto & edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        // return {};
        map<int,int> mp;
        vector<int> dis(n+1, 1e8);
        
        queue<pair<int,int>> q;
        q.push({0,1});
        dis[0] = 0;
        while(q.size()){
            auto top = q.front();
            q.pop();
            int cost = top.first, Node = top.second;
            // cout<<Node<<" "<<cost<<endl;
            for(auto & edge : adj[Node]){
                int upcomingNode = edge.first, price = edge.second;
                // cout<<upcomingNode<<" "<<price<<"||";
                // if(upcomingNode > n)
                //     return {};
                if(cost + price < dis[upcomingNode]){
                    dis[upcomingNode] = cost + price;
                    mp[upcomingNode] = Node;
                    q.push({dis[upcomingNode], upcomingNode});
                }
            }//cout<<endl;
        }
        // for(auto a : dis)cout<<a<<" ";cout<<endl;
        if(dis[n] == 1e8 ) return {-1};
        vector<int> path;
        // for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;
        
        // return {};
        while(mp.find(n) != mp.end()){
            path.push_back(n);
            if(n == 1)break;
            n = mp[n];
        }
        
        reverse(path.begin(),path.end());
        // cout<<1;
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends