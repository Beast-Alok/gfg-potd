//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
        int mod = 1e9+7;
        vector<int> v(n+1);
        v[0] = 1;
        v[1] = 1;
        v[2] = 1;
        for(int i = 3; i < n+1; i++){
            v[i] = (v[i-2]%mod+v[i-3]%mod)%mod;
        }
        
        if(n == 1 or n == 2){
            return 1;
        }else{
            return v[n]%mod;
        }
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
