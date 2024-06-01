//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int count = 0;
        map<char, int> m;
        for(int i = 0; i < s.length(); i++){
            m[s[i]]++;
        }
        
        for(const auto x : m){
            int ch = x.first;
            int f = x.second;
            if(ch%2 == 0 and f%2 == 0){
                count++;
            }else if(ch%2 != 0 and f%2 != 0){
                count++;
            }
        }
        
        return count%2 == 0 ? "EVEN" : "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends