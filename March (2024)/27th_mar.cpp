//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int shortestPath = INT_MAX;

    void dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& visited, int count) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        if (row < 0 || col < 0 || col >= cols || row >= rows || visited[row][col] || 
            (row + 1 < rows && matrix[row + 1][col] == 0) || 
            (row - 1 >= 0 && matrix[row - 1][col] == 0) || 
            (col + 1 < cols && matrix[row][col + 1] == 0) || 
            (col - 1 >= 0 && matrix[row][col - 1] == 0) || 
            matrix[row][col] == 0)
            return;

        if (col == cols - 1) {
            shortestPath = min(shortestPath, count + 1);
            return;
        }

        visited[row][col] = 1;
        dfs(matrix, row + 1, col, visited, count + 1);
        dfs(matrix, row - 1, col, visited, count + 1);
        dfs(matrix, row, col + 1, visited, count + 1);
        dfs(matrix, row, col - 1, visited, count + 1);
        visited[row][col] = 0;
    }

    int findShortestPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            dfs(matrix, i, 0, visited, 0);
        }

        if (shortestPath == INT_MAX)
            return -1;

        return shortestPath;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
