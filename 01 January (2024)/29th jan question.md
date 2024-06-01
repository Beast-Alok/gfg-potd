## 01. Count digit groupings of a number Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1)

Level : `Medium`

### My Approach

**f Function**:

- **Base Case**: If the current index i reaches the end of the string (s.size()), return 1, indicating a valid subarray.
- **Memoization** Check: If the result for the current state (sum, i) is already computed and stored in the memoization table (dp), return the stored result.
- **Initialization**: Initialize variables ans to store the count and curr_sum to calculate the current sum of digits.
- **Loop through the string**: Iterate from the current index j to the end of the string (s.size()).
  - Update curr_sum by adding the digit at index j.
  - If the updated curr_sum is greater than or equal to the given sum, recursively call f for the next index (j+1) and add the result to ans.
- **Memoization**: Store the result in the memoization table (dp) and return ans.

**TotalCount Function**:

- Initialize a memoization table dp with dimensions (1000, string size) and fill it with -1.
- Call the recursive function f with initial parameters: sum = 0, i = 0, s = str, and dp.
- Return the final result.

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