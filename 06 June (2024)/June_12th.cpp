//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int count = 0;
        for(int i = 4; i < n+1; i++){
            bool check = false;
            int temp = i;
            while(temp != 0){
                if(temp%10 == 4 and !check){
                    // cout<<i<<" ";
                    count++;
                    check = true;
                }
                temp = temp/10;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends
