#include <bits/stdc++.h>
using namespace std;

// GFG solution from here
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        map<int,int> f;
        for(int i = 0; i < N; i++){
            ++f[arr[i]];
        }
        for (const auto& pair : f) {
            if (pair.second == 1)
            {
                return pair.first;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}

//code written by alok kumar raghuwanshi 