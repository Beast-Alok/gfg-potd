#include<bits/stdc++.h>
using namespace std;

// GFG solution from here
class Solution {
  public:
    int smallestSubstring(string S) {
        vector<int> f(3,0);
        int l=0,r=0;
        int len = 1e8;
        bool res = 0;

        while(r < S.size() || l < r){
            if (!res && r < S.size())
            {
                ++f[S[r++] - 48];
                if(f[0] && f[1] && f[2]){
                    res = 1;
                }else{
                    res = 0;
                }
            }
            else if (l<r)
            {
                --f[S[l++] - 48];
                if(f[0] && f[1] && f[2]){
                    res = 1;
                }else{
                    res = 0;
                }
            }
            if (res)
            {
                len = min(len, r-l);
            }
        }
        return len == 1e8 ? -1 : len;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}

//code written by alok kumar raghuwanshi