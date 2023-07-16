//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool is(vector<int>&arr, double mid, int k){
	int cnt = 0;
	int j = 1;
	while(j < arr.size()){
		int need = (arr[j] - arr[j-1])/mid;
		// cnt--;
		double temp = (arr[j] - arr[j-1])/mid;
		if(temp > (double)need)cnt += need;
		else cnt += (need-1);
		
		j++;
	}
	return (cnt) <= k;
}

  
    double findSmallestMaxDist(vector<int> &arr, int k){
      long double l = 0.00001, r = 1e9+5, ans = 0;


	while(r-l >= 1e-6){
		double mid = l -(l-r)/2.0;
		bool flag = is(arr, mid, k);
		// cout<<l<<" "<<mid<<" "<<r<<" "<<flag<<endl;
		if(flag){
		    r = mid;
		    ans = mid;
		}
		else l = mid;
	}
	// cout<<l<<" "<<r<<endl;
	// cout<<l<<endl;
	return ans;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends