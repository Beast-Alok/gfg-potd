//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     int countMin(string str){
    //complete the function here
    string temp = str;
    int n = str.size();
    reverse(temp.begin(), temp.end());
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            int take = -1e9;
            int nottake = -1e9;
            if(str[i] == temp[j]){
                take = 1 + dp[i+1][j+1];
            }
            else{
                nottake = max(dp[i+1][j], dp[i][j+1]);
            }
            dp[i][j] = max(take, nottake);
        }
    }
    return n - dp[0][0];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
