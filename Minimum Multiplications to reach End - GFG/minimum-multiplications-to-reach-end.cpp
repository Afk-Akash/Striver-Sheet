//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        q.push({0,start});
        vector<int> dist(100000,INT_MAX);
        dist[start] = 0;
        while(q.size()){
            auto top = q.front();
            q.pop();
            int lvl = top.first, val = top.second;
            if(val == end) return lvl;
            for(auto & integer : arr){
                int newVal = (val * integer)%100000;
                if(dist[newVal] > lvl+1){
                    dist[newVal] = lvl+1;
                    q.push({lvl+1, newVal});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends