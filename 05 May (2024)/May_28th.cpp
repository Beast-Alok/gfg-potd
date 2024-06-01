//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
      int fun(vector<int> &cost,int n,int w,vector<vector<int>> &dp){
            if(w==0) return 0;
            if(n==0) return 1000000007;
            if(dp[n][w]!=-1) return dp[n][w];
            int ans = 1000000007;
            if(cost[n-1]!=-1 and w-n>=0){
                ans = min(fun(cost,n-1,w,dp),cost[n-1]+fun(cost,n,w-n,dp));
            }
            else ans = fun(cost,n-1,w,dp);
            return dp[n][w] = ans;
        }
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<vector<int>> dp(n+1,vector<int>(w+3,-1));
        int ans = fun(cost,n,w,dp);
        if(ans >= 1000000007) return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends
