//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        // code here
        int sum = 0;
        int steps = 0;
        while(sum!=d) {
            sum+=steps;
            if(sum==d)
                return steps;
            
            else if(sum>d) {
                int temp = sum-d;
                if(temp%2==0)
                    break;
            }
            ++steps;
        }


        return steps;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends
