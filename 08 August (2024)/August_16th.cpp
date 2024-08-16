//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
         vector<int> order = {x, y, z};
        
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));
        dp[n][0] = 0;
        dp[n][1] = 0;
        dp[n][2] = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < 3; j++) {
                if(i + order[j] <= n) {
                    for(int k = 0; k < 3; k++)
                        dp[i][j] = max(dp[i][j], dp[i + order[j]][k] + 1);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 3; i++) {
            ans = max(ans, dp[0][i]);
        }
        return (ans == INT_MIN ? 0 : ans);
        
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
