//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        vector<int> v;
        int a = 0, b = 1;
        long long int cst = 1e9+7;
        for(int i = 0; i <= n; i++){
            if(i == 0){
                v.push_back(0);
            }else if(i == 1){
                v.push_back(1);
            }else{
                int c = (a+b)%cst;
                v.push_back(c);
                a=b;
                b=c;
            }
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
