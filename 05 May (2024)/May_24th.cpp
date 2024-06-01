//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int mod = 1e9 + 7;
    int solve(vector<int>& arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1,0));
        
        // for first column tar = 0, is possible if we take nothing
        for(int i=0;i<n;i++) dp[i][0] = 1;


        // agr target bhi 0 and arr[0] tb 2 cases
        if(arr[0] == 0) dp[0][0] = 2;
        
        // target = arr[0] is always possible 
        if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
        
        for(int ind=1;ind<n;ind++){
            for(int s=0;s<=target;s++){

                int notTake = dp[ind-1][s];
                int take = 0;
                if(arr[ind] <= s){
                    take = dp[ind-1][s-arr[ind]];
                }

                dp[ind][s] = (notTake + take) % mod;
            }
        }
        return dp[n-1][target];
    }


    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(int i:arr) sum += i;
        
        if(sum - d < 0 || (sum-d) % 2) return 0;
        
        return solve(arr,(sum-d)/2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
