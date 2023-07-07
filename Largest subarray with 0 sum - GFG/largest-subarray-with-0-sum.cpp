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
        unordered_map<int,int> mp;
        // Your code here
        vector<int> v(1, A[0]);
        mp[A[0]] = 0;
        mp[0] = -1;
        for(int i = 1; i < n; i++){
            v.push_back(v.back() + A[i]);
            if(!mp.count(v.back()))mp[v.back()] = i;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, i - mp[v[i]]);
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