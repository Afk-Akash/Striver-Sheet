//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        vector<int> pre(1,A[0]);
        for(int i = 1; i < n; i++){
            pre.push_back(pre.back() + A[i]);
        }
        // if(pre.back() == 0) return n;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mp.find(pre[i]) != mp.end()){
                ans = max(ans, i - mp[pre[i]]);
                // cout<< " k ";pre[i]-
                continue;
            }
            mp[pre[i]] = i;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends