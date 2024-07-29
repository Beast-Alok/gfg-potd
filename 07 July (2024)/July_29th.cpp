//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int sum;
        int i=0;
        int max=0;
        int maxI=0;
        int count=0;
        int n=arr.size();
        int m=arr[0].size();
        while(i<n){
            sum=0;
            for(int j=0;j<m;j++){
                sum +=arr[i][j];
            }
            if(sum>max) {maxI=i;
                max=sum;
            }
           // if(sum==max) count++;
            i++;
            
        }
        if(max==0) return -1;
        return maxI;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
