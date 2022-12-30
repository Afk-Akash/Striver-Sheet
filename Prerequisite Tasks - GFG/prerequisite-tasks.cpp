//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& adj) {
	    // Code here
	     vector<int> graph[n];
        for(int i = 0; i < adj.size(); i++){
            graph[adj[i].first].push_back(adj[i].second);
        }

        vector<int> in(n,0);
        for(int i = 0; i< n;i++){
            for(auto & a : graph[i])in[a]++;
        }
        vector<int> q;
        for(int i = 0; i < n; i++)if(!in[i])q.push_back(i);
        for(int i = 0; i < q.size(); i++){
            for(auto & edge : graph[q[i]]){
                if(!--in[edge])q.push_back(edge);
            }
        }
        
        return q.size() != n ? 0:1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends