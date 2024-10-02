//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void rotatearray(vector<int> &arr)
    {
        arr.insert(arr.begin(),arr[arr.size()-1]);
        arr.pop_back();
    }
    int rotateDelete(vector<int> &arr) {
        int n=arr.size();
        int sz=n/2;
        for(int i=1;i<=sz;i++)
        {
            rotatearray(arr);
            n=arr.size();
            arr.erase(arr.begin()+(n-i));
        }
        return arr[0];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
