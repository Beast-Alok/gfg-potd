#include <bits/stdc++.h>
using namespace std;
// gfg solution from here
class Solution{
public:
    pair<int, string> solve(int i, int j, int p[], vector<vector<pair<int, string>>>&dp){
        if (i == j) return {0, string(1, static_cast<char>('A' + i-1))};
        if(dp[i][j].first!=-1) return dp[i][j];
        int mini=1e9;
        string temp="";
        for(int k=i; k<j; k++){
            pair<int, string>p1=solve(i, k, p, dp);
            pair<int, string>p2=solve(k+1, j, p, dp);
            int total=p[i-1]*p[k]*p[j]+p1.first+p2.first;
            if(total<mini){
                temp="("+p1.second+p2.second+")";
                mini=total;
            }
        }
        return dp[i][j]={mini, temp};
    }

    string matrixChainOrder(int p[], int n){
        vector<vector<pair<int, string>>>dp(n+1, vector<pair<int, string>>(n+1, {-1, ""}));
        return solve(1, n-1, p, dp).second;
    }
};

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// code written by alok kumar raghuwanshi