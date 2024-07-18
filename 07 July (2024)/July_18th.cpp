//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
    if(arr.size()==1)
       return 1;
       
       if(arr.size()==2)
       {
           if(arr[0]==arr[1])
           return 1;
           return 2;
       }
        int ans=1;
        int pre=arr[0];
       
        for(int i=1;i<arr.size()-1;i++)
       {
           if(arr[i]>arr[i+1] && arr[i]>pre)
           ans++,pre=arr[i];
           else if(arr[i]<pre && arr[i]<arr[i+1])
           ans++,pre=arr[i];
       }
       return ans+1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
