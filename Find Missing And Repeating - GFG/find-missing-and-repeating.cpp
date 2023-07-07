//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        long long sum = 1LL*n*(n+1) >> 1;
        long long sumActual = accumulate(arr.begin(), arr.end(), 1LL*0);
        
        long long A_B = sum - sumActual;
        
        long long sqrSum = 1LL*n*(n+1)*(2*n+1)/6;
        long long sqrActual = 0;
        for(auto & a : arr) sqrActual += 1LL*a*a;
        
        long long sqrDiff = sqrSum - sqrActual;
        long long AsumB = sqrDiff/A_B;
        
        long long a = (AsumB+A_B)>>1, b = AsumB-a;
        // if(a < b)swap(a,b);
        return {b,a};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends