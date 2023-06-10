//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:

    int findPlatform(int arr[], int dep[], int n)
    {
        vector<int> time(2401, 0);
        for(int i = 0; i < n; i++){
            time[arr[i]] += 1;
            time[dep[i]+1] -= 1;
        
        }
        
        for(int i = 1; i < 2401; i++){
            time[i] += time[i-1];
        }
        
        int ans = *max_element(time.begin(), time.end());
        
        return ans;
    	
    }
    
    static bool cmp(pair<int,int> &a , pair<int,int> &b){
        return a.second < b.second;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends