//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        if(n < 100){
            return "false";
        }
        int copy = n;
        int digit = log10(n)+1;
        int sum = 0;
        while(n != 0){
            sum += round(pow(n%10, digit));
            n = n / 10;
        }
        
        if(copy == sum){
            return "true";
        }else{
            return "false";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
