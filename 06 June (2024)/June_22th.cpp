//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        long long num = -1;
        long long temp = 0;
        for(int i = 0; i < sentence.length()+1; i++){
            if(sentence[i]-48 >= 0 and sentence[i]-48 <= 8 and i < sentence.length()){
                temp = temp*10 + sentence[i]-48;
            }
            else if(sentence[i]-48 == 9 and i < sentence.length()){
                temp = 0;
                while(sentence[i]-48 >= 0 and sentence[i]-48 <= 9 and i < sentence.length()){
                    i++;
                }
            }
            else{
                num = max(num, temp);
                temp = 0;
            }
        }
        
        return num == 0 ? -1: num;
        
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
