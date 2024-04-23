//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        int mod = 1e9+7;
        int p = 0;
        int q = 1;
        if(n == 1)  return q;
        if(n == 2)  return q;
        for(int i = 2 ; i <= n ; i++)
        {
            int curr = (p%mod + q%mod)%mod;
            p = q;
            q = curr;
        }
        
        return q;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
