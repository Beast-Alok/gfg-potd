//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
    // Sort both arrays
    std::sort(a, a + n);
    std::sort(b, b + m);

    // Calculate sums of elements in both arrays
    int sum1 = std::accumulate(a, a + n, 0);
    int sum2 = std::accumulate(b, b + m, 0);

    // If arrays are already equal, no swap needed
    if (std::equal(a, a + n, b))
        return 1;

    // Calculate the difference between sums
    int diff = std::abs(sum1 - sum2);

    // If difference is odd, no way to make sums equal
    if (diff % 2 != 0)
        return -1;

    // Target difference for each array
    int targetDiff = diff / 2;

    // Perform binary search for each element in a[]
    for (int i = 0; i < n; i++) {
        if (std::binary_search(b, b + m, a[i] + targetDiff) || 
            std::binary_search(b, b + m, a[i] - targetDiff))
            return 1;
    }

    return -1;
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
