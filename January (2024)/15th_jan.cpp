#include<bits/stdc++.h>
using namespace std;

// gfg solution from here
class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<int> dp(total + 1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = total; j >= 0; j--) {
                if(cost[i] <= j) {
                    int rem = j - cost[i] + (cost[i] * 9) / 10;
                    dp[j] = max(dp[j], 1 + dp[rem]);
                }
            }
        }
        return dp[total];
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// code written by alok kumar raghuwanshi