//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        
        int pairsum = 0;
        int maxi = -1;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            
            if(arr[i]>maxi)
                maxi = arr[i];
            
        }
        
        for(int i=0;i<n;i++){
            
            int sum = maxi + arr[i];
            if(sum > pairsum && arr[i]!=maxi)
                pairsum = sum;
            
        }
        
        return pairsum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends
