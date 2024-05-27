//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve2(int  n , vector<int>&a)
    {
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));
        for(int index = n-1 ; index>=0 ; index-- )
        {
            for(int prev = n-2 ; prev >= -1 ; prev--)
            {
                    int include = 0;
                    if(prev == -1 or abs(a[prev] - a[index]) == 1)
                    {
                        include = 1 + dp[index + 1][index+1];
                    }
                    int exclude = dp[index+1][prev+1];
                    dp[index][prev+1] = max(include , exclude);
            }
        }
        return dp[0][0];
    }
    int longestSubseq(int n, vector<int> &a) {
        return solve2(n , a);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends
