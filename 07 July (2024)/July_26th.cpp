//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        vector<int> arr(26,0);
       int n = str.size();
       int ch = 0;
       for(int i=0; i<n; i++){
           if(str[i]!=' '){
               arr[str[i]-'a'] = 1;
               ch++;
           }
       }
       int c = 0;
       for(int i=0; i<26; i++){
           if(arr[i] == 0){
               c++;
           }
       }
       if(ch<26 || c>k){
           return false;
       }
       return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
