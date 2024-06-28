//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool isPalindrome(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            if (arr[left] != arr[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        
        int n = arr.size();
    
        // Check rows
        for (int i = 0; i < n; ++i) {
            if (isPalindrome(arr[i])) {
                return to_string(i) + " R";
            }
        }
    
        // Check columns
        for (int j = 0; j < n; ++j) {
            vector<int> column;
            for (int i = 0; i < n; ++i) {
                column.push_back(arr[i][j]);
            }
            if (isPalindrome(column)) {
                return to_string(j) + " C";
            }
        }
    
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends
