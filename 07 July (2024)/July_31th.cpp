//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
         string s="";
        bool b=true;
        int min=INT_MAX;
        if(arr.size()==1)
        {
            return arr[0];
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i].length()<min)
            {
                min=arr[i].length();
            }
        }
        for(int i=0;i<min;i++)
        {
            for(int j=1;j<arr.size();j++){
                if(arr[0][i]!=arr[j][i])
                {
                    b=false;
                }
            }
            if(b)
            {
                s+=arr[0][i];
            }
            else if(s.length())
            {
                return s;
          
           }
        }
        return "-1";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends
