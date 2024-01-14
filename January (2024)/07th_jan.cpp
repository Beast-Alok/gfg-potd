#include <bits/stdc++.h>
using namespace std;

// GFG solution from here
class Solution {
  public:
    bool check(int arr[], int mid, int k, int n){
        int cut = 1, sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum > mid){
                sum = arr[i];
                cut++;
            }
        }
        return cut <= k;
    }
    
    int splitArray(int arr[] ,int N, int K) {
        int low = 0, high = 0, ans = 0;
        for(int i=0; i < N; i++){
            high += arr[i], low = max(low,arr[i]);
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(check(arr,mid,K,N)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}

//code written by alok kumar raghuwanshi