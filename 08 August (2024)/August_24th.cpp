//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int fun(int i,int W,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp){
        if(i<0 || W<0)
            return 0;
        if(dp[i][W]!=-1)
            return dp[i][W];
        
        int t=0;
        int nt=0;
        
        if(wt[i]<=W)
            t=val[i]+fun(i-1,W-wt[i],wt,val,dp);
        nt=fun(i-1,W,wt,val,dp);
        
        return dp[i][W]=max(t,nt);    
            
    }
    
    
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n=val.size();
        
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        
        return fun(n-1,W,wt,val,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends
