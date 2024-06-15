//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {

        vector<vector<int>> a(10);

        a[0] = {8};

        a[1] = {2,4};

        a[2] = {1,3,5};

        a[3] = {2,6};

        a[4] = {1,5,7};

        a[5] = {2,4,6,8};

        a[6] = {3,5,9};

        a[7] = {8,4};

        a[8] = {7,9,5,0};

        a[9] = {6,8};

        vector<long long> pre(10, 1);

        vector<long long> curr(10, 1);

        while(--n){  

            for(int i=0; i<10; i++){

                curr[i] = pre[i];

                for(auto j : a[i]){

                    curr[i] += pre[j];

                }

            }

            pre = curr;

        }

        long long sum = 0;

        for(int i=0; i<10; i++){

            sum += curr[i];    

        }

        return sum;

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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
