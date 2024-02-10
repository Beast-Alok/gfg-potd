#include<bits/stdc++.h>
using namespace std;

// gfg solution from here
class Solution {
public:
    long find(int n, int k, vector<vector<int>> &arr, int x, int y, vector<vector<vector<long>>> &dp) {
        if (x >= n || y >= n || k < 0) return 0;
        if (x == n - 1 && y == n - 1 && k - arr[x][y] == 0) return 1;
        if (dp[x][y][k] != -1) return dp[x][y][k];
        
        long a = find(n, k - arr[x][y], arr, x + 1, y, dp);
        long b = find(n, k - arr[x][y], arr, x, y + 1, dp);
        
        return dp[x][y][k] = a + b;
    }

    long long numberOfPath(int n, int k, vector<vector<int>> &arr) {
        vector<vector<vector<long>>> dp(n, vector<vector<long>>(n, vector<long>(k + 1, -1))); // Initialize DP table with -1
        return find(n, k, arr, 0, 0, dp);
    }
};

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}

// code written by alok kumar raghuwanshi