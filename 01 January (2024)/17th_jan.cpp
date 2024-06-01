#include <bits/stdc++.h>
using namespace std;

//gfg solution from here
class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        do {
            res.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr, n);
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// code written by alok kumar raghuwanshi