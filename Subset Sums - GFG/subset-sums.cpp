//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int sum = 0;
        fun(0, N, arr, ans,sum);
        return ans;
    }
    
    void fun(int ind, int n, vector<int> &arr, vector<int> &ans, int sum){
        if(ind == n){
            ans.push_back(sum);
            return ;
        }
        
        fun(ind + 1, n , arr, ans, sum);
        fun(ind + 1, n, arr, ans, sum + arr[ind]);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends