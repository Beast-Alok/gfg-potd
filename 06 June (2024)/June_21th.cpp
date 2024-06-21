//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        float n1 = 0, d1 = 0, n2 = 0, d2 = 0;
        int number = 0;
        for(int i = 0; i < str.length();){
            if(str[i] == '/' or str[i] == ','){
                // cout<<i<<endl;
                i++;
                if(str[i-1] == ',') i++;
                number++;
            }else{
                // cout<<i<<endl;
                if(number == 0) n1 = n1*10 + str[i]-48;
                else if(number == 1) d1 = d1*10 + str[i]-48;
                else if(number == 2) n2 = n2*10 + str[i]-48;
                else d2 = d2*10 + str[i]-48;
                i++;
            }
        }
        if((d1 == 0 and d2 == 0) or (n1/d1 == n2/d2)){
            return "equal";
        }else if(d1 == 0 or n1/d1 > n2/d2){
            cout<<n1<<"/"<<d1;
            return "";
        }else{
            cout<<n2<<"/"<<d2;
            return "";
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
