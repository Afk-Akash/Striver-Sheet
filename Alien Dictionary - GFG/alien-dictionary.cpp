//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        
        for(int i = 1; i < N; i++){
            auto ss = dict[i-1], sss = dict[i];
            for(int j = 0; j < min(ss.size(), sss.size()); j++){
                if(ss[j] != sss[j]){
                    adj[ss[j] - 'a'].push_back(sss[j] - 'a');
                    break;
                }
            }
        }
        vector<int> topo;
        vector<bool> vis(K,false);
        for(int i = 0; i < K; i++){
            if(!vis[i]){
                dfs(i,adj,topo,vis);
            }
        }
        string str = "";
        for(int i = topo.size()-1; i>= 0; i--){
            str += topo[i] + 'a';
        }
        return str;
    }
    
    void dfs(int node, vector<int> adj[], vector<int> &t, vector<bool> &vis){
        vis[node] = true;
        for(auto & edge : adj[node]){
            if(vis[edge])continue;
            dfs(edge, adj, t, vis);
        }
        t.push_back(node);
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends