#include<bits/stdc++.h>
using namespace std;
class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};
// gfg solution from here
class Solution {
  public:
    void dfs(vector<int>* adj,int node,vector<int>& visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            dfs(adj,it,visited);
        }
    }
    int isTree(int n, int m, vector<vector<int>> &edg) {
        
        if((n-m)!=1)
        return 0;
        
        vector<int> adj[n];
        for(auto it:edg)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        dfs(adj,0,visited);
        
        for(auto it:visited)
        {
            if(it==0)
            return 0;
        }
        return 1;
    }
};
int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        int m; 
        scanf("%d",&m);
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        cout<<res<<endl;
    }
}
// code written by alok kumar raghuwanshi