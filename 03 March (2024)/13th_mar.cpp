//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         bool flag =false;
        int dig =0;
        vector<int> res;
        while(dig <= 2*mat.size()-2){
            if(flag){
                for(int i=0; i<=dig; i++){
                    if(max(dig-i, i) < mat.size()){
                        res.push_back(mat[i][dig-i]);
                    }
                    
                }
                flag =false;
            }
            else{
                for(int j=0; j<=dig; j++){
                    if(max(dig-j, j) < mat.size()){
                        res.push_back(mat[dig-j][j]);
                    }
                }
                flag =true;
            }
            dig++;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends
