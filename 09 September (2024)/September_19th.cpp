//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
    vector<string> words;
    stringstream ss(S);
    string word;
    
    while(getline(ss , word , '.')){
        words.push_back(word);
    }
    
    reverse(words.begin() , words.end());
    string ans = words[0];
    for(int i = 1 ; i < words.size() ; i++){
        ans += "." + words[i];
    }
    
    return ans;
    
    } 
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends
