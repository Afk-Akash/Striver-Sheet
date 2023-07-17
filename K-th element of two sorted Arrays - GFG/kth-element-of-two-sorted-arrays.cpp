//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int total = n + m, leftSide = k-1;
        if(n > m) return kthElement(arr2, arr1, m , n, k);
        
        int l = 0, r = n;
        
        while(l <= r){
            int cut1 = l - (l-r)/2;
            int cut2 = leftSide - cut1;
            if(cut1 >= k){
                r = cut1 - 1;
                continue;
            }
            if(cut2 > m){
                l = cut1 + 1;
                continue;
            }
            
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            
            if(l1 <= r2 && l2 <= r1)return min(r1,r2);
            if(l1 > r2) r = cut1 - 1;
            else l = cut1 + 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends