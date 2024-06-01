//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    void solve(int n, string str, vector<string>& ans, int ones, int zeros) {
        if (n == 0) {
            ans.push_back(str);
            return;
        }

        if (ones + 1 >= zeros) {
            solve(n - 1, str + "1", ans, ones + 1, zeros);
        }

        if (ones >= zeros + 1) {
            solve(n - 1, str + "0", ans, ones, zeros + 1);
        }
    }
public:	
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
        solve(n, "", ans, 0, 0  );
        return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
