#include <bits/stdc++.h>
using namespace std;
// gfg solution from here
class Solution{
public:
    vector<int> recamanSequence(int n){
        int arr[1000000] = {0};
        vector<int> v;
        for(int i=0; i<n; i++){
            if(i==0){
                v.push_back(0);
                arr[0]++;
            }
            else{
                int x = v[i-1]-i;
                if(x<0){
                    int y = v[i-1]+i;
                    v.push_back(y);
                    arr[y]++;
                }
                else{
                    if(arr[x]!=0){
                        int k = v[i-1]+i;
                        v.push_back(k);
                        arr[k]++;
                    }
                    else{
                        v.push_back(x);
                        arr[x]++;
                    }
                }
            }
        }
        return v;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}

// code written by alok kumar raghuwanshi