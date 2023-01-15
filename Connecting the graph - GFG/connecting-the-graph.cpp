//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    
    class disjointSet {

public:
	vector<int> rank, parent, size;
	disjointSet(int n) {
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		iota(parent.begin(), parent.end(), 0);
	}

	int findParent(int n) {
		if (n == parent[n]) return n;

		return parent[n] = findParent(parent[n]);
	}

	void unionByRank(int a, int b) {
		int pA = findParent(a), pB = findParent(b);
		if (pA == pB) return ;

		if (rank[pA] < rank[pB]) {
			parent[pA] = pB;
		} else if (rank[pB] < rank[pA]) {
			parent[pB] = pA;
		} else {
			parent[pA] = pB;
			rank[pB]++;
		}
	}

	void unionBySize(int a, int b) {
		int pa = findParent(a), pb = findParent(b);
		if(pa == pb) return ;
		if (size[pa] < size[pb]) {
			parent[pa] = pb;
			size[pb] += size[pa];
		} else if (size[pb] < size[pa]) {
			parent[pb] = pa;
			size[pa] += size[pb];
		} else {
			parent[pb] = pa;
			size[pa] += size[pb];
		}
	}
};

  public:
    int Solve(int n, vector<vector<int>>& edge) {
        disjointSet ds(n);
        int cnt = 0, c = 0;
        for(auto e : edge){
            int pa = ds.findParent(e[0]), pb = ds.findParent(e[1]);
            if(pa == pb){
                cnt++;
                continue;
            }
            ds.unionBySize(e[0], e[1]);
        }
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i)c++;
        }
        // cout<<cnt<<" "<<c<<endl;''
        if(c-1 <= cnt) return c-1;
        return -1;
    }
};








































//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends