class Solution
{
    public:
        int maxSum(int N)
        {
            vector<int> dp(N+1,0);
            for(int n=0;n<=N;n++) dp[n] = max(n,dp[n/2]+dp[n/3]+dp[n/4]);
            return dp[N];
        }
};
