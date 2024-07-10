//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> dirX={1,0,0,-1};
    vector<int> dirY={0,1,-1,0};
    void dfs(vector<vector<int>> &parent,map<int,int>&mp,int p,int i,int j, vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || parent[i][j]!=-1 || grid[i][j]!=1){
            return;
        }
        parent[i][j]=p;
        mp[p]++;
        for(int k=0;k<4;k++){
            dfs(parent,mp,p,i+dirX[k],j+dirY[k],grid);
        }
    }
    int MaxConnection(vector<vector<int>>& grid) {
        vector<vector<int>> parent(grid.size(),vector<int>(grid[0].size(),-1));
        map<int,int> mp;
        int p=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1 && parent[i][j]==-1){
                    dfs(parent,mp,p,i,j,grid);
                    p++;
                }
            }
        }
        
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    set<int> s;
                    int curr=1;
                    for(int k=0;k<4;k++){
                        int x=i+dirX[k];
                        int y=j+dirY[k];
                        if(x>-1 && y>-1 && x<grid.size() && y<grid[0].size()){
                            if(parent[x][y]!=-1 && s.find(parent[x][y])==s.end()){
                                s.insert(parent[x][y]);
                                curr+=mp[parent[x][y]];
                            }
                        }
                    }
                   
                    maxi=max(curr,maxi);
                }
            }
        }
        for(auto &i:mp){
            maxi=max(maxi,i.second);
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends
