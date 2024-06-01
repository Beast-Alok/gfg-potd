#include <bits/stdc++.h> 
using namespace std; 
// gfg solution from here
class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        set<vector<int>> st;
        vector<int> ans;
        for(int i = 0; i<M; i++){
            auto val = st.find(matrix[i]);
            if(val != st.end()){
                ans.push_back(i);
            }else{
                st.insert(matrix[i]);
            }
        }
        return ans;
    } 
};

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);
        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// code written by alok kumar raghuwanshi