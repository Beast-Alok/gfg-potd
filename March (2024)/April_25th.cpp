//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int r, int c, vector<vector<int>> mat) {
        // code here
        if(r < 3 or c < 3){
            return -1;
        }
        
        int sum = 0;
        int tempc = 2;
        while(tempc < c){
            int tempr = 2;
            while(tempr < r){
                int temp = 0;
                for(int i = tempc-2; i <= tempc; i++){
                    temp += mat[tempr-2][i];
                    temp += mat[tempr][i];
                }
                temp += mat[tempr-1][tempc-1];
                
                if(temp > sum){
                    sum = temp;
                }
                tempr++;
            }
            tempc++;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends
