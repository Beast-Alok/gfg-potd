//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int n=arr.size();
       
       int jumps=0;  //we will store number of jumps here
       int maxReach=0,curReach=0; // we can always be at the first element
       
       for(int i=0;i<n;i++){
           if(i>maxReach)return -1;
           if(i>curReach){
               curReach=maxReach;
               jumps++;
           }
           maxReach=max(maxReach,i+arr[i]);
       }
       return jumps;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
