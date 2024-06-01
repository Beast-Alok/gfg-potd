#include<bits/stdc++.h>
using namespace std;

// gfg solution from here
class Solution {
public:
    int timer = 1;
    void dfs(int node,int parent,int low[],int first[],vector<int>adj[],vector<vector<int>>&bridges,vector<int>&vis)
    {
        vis[node] = 1;
        first[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node])
        {
            if(it == parent) continue;
            if(vis[it] == 0)
            {
                dfs(it,node,low,first,adj,bridges,vis);
                low[node] = min(low[it],low[node]);
                if(low[it] > first[node])
                {
                    if(node>it)
                    bridges.push_back({it,node});
                    else
                    bridges.push_back({node,it});
                }
            }
            else
            {
                low[node] = min(low[it],low[node]);
            }
        }
        
    }
    vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
        int low[v];
        int first[v];
        vector<int>vis(v,0);
        vector<vector<int>>bridges;
        dfs(0,-1,low,first,adj,bridges,vis);
        sort(bridges.begin(),bridges.end());
        return bridges;
    }
};

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// code written by alok kumar raghuwanshi