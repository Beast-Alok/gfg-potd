#include <bits/stdc++.h>
using namespace std;

// gfg solution from here
class Solution{
public:
     int solve(int i, int m){
        if(i==0)
            return 1;
        if(m==0)
            return 0;
        int take=solve(i-1,m/2);
        int notTake=solve(i,m-1);
        return take+notTake;
    }
    int numberSequence(int m, int n){
        return solve(n,m);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// code written by alok kumar raghuwanshi