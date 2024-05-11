//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void solve(long long n,vector<long long>&ans){
    if(n<=1)return ;
      
      if(n%2==0){
          n=sqrt(n);
          ans.push_back(n);
          solve(n,ans);
      }
      else{
           n=n*sqrt(n);
          ans.push_back(n);
          solve(n,ans);
      }
  }
 
    vector<long long> jugglerSequence(long long n) {
      
      vector<long long>ans;
      ans.push_back(n);
     solve(n,ans);
     return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
