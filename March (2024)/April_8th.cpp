//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int n, int arr[], vector<vector<int>>& dp, int s, int e) {
        if (s > e) {
            return 0;
        }
        if (dp[s][e] != -1) {
            return dp[s][e];
        }
        int op1 = arr[s] + min(solve(n, arr, dp, s + 2, e), solve(n, arr, dp, s + 1, e - 1));
        int op2 = arr[e] + min(solve(n, arr, dp, s + 1, e - 1), solve(n, arr, dp, s, e - 2));
        return dp[s][e] = max(op1, op2);
    }
    
    long long maximumAmount(int n, int arr[]) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(n, arr, dp, 0, n - 1);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends
