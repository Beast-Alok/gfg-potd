//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string s1, string s2) {
        // code here
        int mod = 1000000007;
        int m = s2.length();
        vector<int>prev(m+1,0), cur(m+1,0);
        for(int n = 0; n <= s1.length(); n++){
            for(int m = 0 ; m <= s2.length(); m++){
                if(m == 0) prev[m] = cur[m] = 1;
                else if(s1[n-1] == s2[m-1]){
                    cur[m] = (prev[m-1] + prev[m])%mod;
                }
                else{
                    cur[m] = prev[m]%mod;
                }
            }
            prev = cur;
        }
        return prev[s2.length()];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends
