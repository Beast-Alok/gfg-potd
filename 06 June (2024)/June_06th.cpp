//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long s1 = 0;
        long long ts = 0;
        
        for (int i = 0; i < n; i++) {
            s1 += (long long)i * a[i];  
            ts += (long long)a[i];      
        }
        
        long long maxi = s1;
        
        
        for (int i = n - 1; i >= 1; i--) {
            s1 = s1 + ts - (long long)n * a[i];  
            if (maxi < s1) {
                maxi = s1;
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends
