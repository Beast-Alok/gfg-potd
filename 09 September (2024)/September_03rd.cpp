//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
		// memoized code byshifting the indices by 1 
// 	int LCS(int i,int j,string &s1,string &s2,vector<vector<int>>& dp){
// 	    if(i==0 || j==0) return 0;
	    
// 	    if(dp[i][j]!=-1) return dp[i][j];
	    
// 	    if(s1[i-1]==s2[j-1]) return dp[i][j]=1 + LCS(i-1,j-1,s1,s2,dp);
	    
// 	    return dp[i][j]=max(LCS(i,j-1,s1,s2,dp),LCS(i-1,j,s1,s2,dp));
// 	}


        // memoized code
	int LCS(int i,int j,string &s1,string &s2,vector<vector<int>>& dp){
	    if(i<0 || j<0) return 0;
	    
	    if(dp[i][j]!=-1) return dp[i][j];
	    
	    if(s1[i]==s2[j]) return dp[i][j]=1 + LCS(i-1,j-1,s1,s2,dp);
	    
	    return dp[i][j]=max(LCS(i,j-1,s1,s2,dp),LCS(i-1,j,s1,s2,dp));
	}
	

	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	   // (l1-lcs) + (l2-lcs)
	   int n=str1.size(),m=str2.size();
	   vector<vector<int>>dp(n,vector<int>(m,-1));
	   int lcs=LCS(n-1,m-1,str1,str2,dp);
	   
	   return (n+m-2*lcs);
	   
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
