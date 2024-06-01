//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    if(n == 0){
		        return 1;
		    }
		    
		    long long int temp = PowMod(x,n/2,M);
		    long long int ans = (temp%M * temp%M)%M;
		    
		    if(n%2 == 0){
		        return ans;
		    }else{
		        return (x%M * ans%M)%M;
		    }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends
