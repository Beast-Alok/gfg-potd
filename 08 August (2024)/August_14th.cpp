//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int n =str1.size(),m = str2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1));
        
        for(int i =0;i<=m;i++){
            dp[0][i] =0;
        }
        for(int i =0;i<=n;i++){
            dp[i][0] =0;
        }
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                dp[i][j] =dp[i -1][j- 1];
                if(str1[i -1] == str2[j -1]){
                    dp[i][j] = 1 + dp[i -1][j -1];
                }else{
                    dp[i][j] =0;
                }
            }
        }
        int ans =0;
        for(int i =0;i<=n;i++){
            for(int j =0;j<=m;j++){
                ans=max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends
