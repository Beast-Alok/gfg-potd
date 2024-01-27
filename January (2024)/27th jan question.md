## 01. Brackets in Matrix Chain Multiplication Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1)

Level : `Hard`

### My Approach

- The `solve` function is a recursive helper function that calculates the minimum cost and the corresponding parenthetical expression for multiplying matrices from index `i` to `j` in the array `p`.
- It uses a 2D vector `dp` to memoize already computed subproblems. The memoization is based on the minimum cost and the corresponding expression.
- The base case is when `i` is equal to `j`, in which case there is no multiplication needed, and the cost is 0 with the matrix name as a single character.
- The function iterates over possible split points `k` between `i` and `j` and recursively calculates the cost for the left and right parts. The total cost includes the cost of the current multiplication and the costs of the subproblems.
- The minimum cost and corresponding expression are updated if the current combination yields a lower cost.
- The final result is stored in the memoization table and returned.
- The `matrixChainOrder` function initializes the memoization table and calls the `solve` function to get the final result.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n^3)
- **Auxiliary Space Complexity** : O(n^2)

### Code (C++)
```cpp
class Solution{
public:
    pair<int, string> solve(int i, int j, int p[], vector<vector<pair<int, string>>>&dp){
        if (i == j) return {0, string(1, static_cast<char>('A' + i-1))};
        if(dp[i][j].first!=-1) return dp[i][j];
        int mini=1e9;
        string temp="";
        for(int k=i; k<j; k++){
            pair<int, string>p1=solve(i, k, p, dp);
            pair<int, string>p2=solve(k+1, j, p, dp);
            int total=p[i-1]*p[k]*p[j]+p1.first+p2.first;
            if(total<mini){
                temp="("+p1.second+p2.second+")";
                mini=total;
            }
        }
        return dp[i][j]={mini, temp};
    }

    string matrixChainOrder(int p[], int n){
        vector<vector<pair<int, string>>>dp(n+1, vector<pair<int, string>>(n+1, {-1, ""}));
        return solve(1, n-1, p, dp).second;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.