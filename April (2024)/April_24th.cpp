//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int ways(int x, int y)
    {
        //code here.
        int mod=1000000007;

        long long int dp[y+1][x+1];
        for(int i=0;i<=y;i++)
        {
            for(int j=0;j<=x;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
    
                    dp[i][j] %= mod;
                }
            }
        }
        
        return dp[y][x];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends
