//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
     void solve(int idx,vector<int>adj[],int &ed,int &ver,vector<int>&vis)
  {
    vis[idx]=1;
    ed+=adj[idx].size();
    for(auto itr:adj[idx])
    {
        if(!vis[itr])
        {
            ++ver;
            solve(itr,adj,ed,ver,vis);
        }
    }
    return;
  }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[v];
        vector<int>vis(v,0);
        int ans=0;
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
            adj[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        for(int i=0;i<v;i++)
        {
            if(vis[i]==0)
            {
                int ed=0;
                int ver=1;
                solve(i,adj,ed,ver,vis);
                if(ed==ver*(ver-1))
                {
                    ++ans;
                }
            }
            
        }
        return ans;
    }    
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends
