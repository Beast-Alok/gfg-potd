## 01. Find all Critical Connections in the Graph Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/critical-connections/1)

Level : `Hard`

### My Approach

**cloneGraph Method**:

- It has a member variable `timer` to keep track of the order in which nodes are visited during the depth-first search (DFS).
- The `dfs` function is a recursive DFS function that finds critical connections in the graph using Tarjan's algorithm. It updates the `low` and `first` arrays, and whenever it encounters a bridge, it adds it to the `bridges` vector.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(v + e)
- **Auxiliary Space Complexity** : O(v)

### Code (C++)
```cpp
//User function Template for C++

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

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.