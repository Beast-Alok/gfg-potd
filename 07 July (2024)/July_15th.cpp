//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {  public:
    string smallestNumber(int s, int d) {
        // code here
        
        string num = "";
        
       if(9*d < s){
           return "-1";
       }
       else if(9*(d-1) < s){
           for(int i = 0; i < d; i++){
               if(s-9 > 0){
                   num.insert(0, 1, '9');
                   s = s-9;
               }else{
                   char temp = 48+s;
                   s = 0;
                   num.insert(0, 1, temp);
               }
           }
           
           return num;
       }
       else{
           num = "1";
           s--;
           for(int i = 1; i < d; i++){
               if(s-9 > 0){
                   num.insert(1, 1, '9');
                   s = s-9;
               }else{
                   char temp = 48+s;
                   s = 0;
                   num.insert(1, 1, temp);
               }
           }
           
           return num;
       }
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends
