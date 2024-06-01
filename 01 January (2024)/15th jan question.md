## 01. Grinding Geek Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/grinding-geek/1)

Level : `Medium`

### My Approach
- Initialize a 1D vector dp with size (total + 1) and initialize all elements to 0.
- Loop through the courses in reverse order (from last course to the first).
  - Loop through the total budget in reverse order.
    - Check if the cost of the current course is less than or equal to the remaining budget.
      - Calculate the remaining budget after taking the current course.
      - Update the dp array with the maximum value between the current value and taking the course.
- The final result is stored in dp[total], representing the maximum number of courses that can be taken with the given total budget.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n*total)
- **Auxiliary Space Complexity** : O(n*total)

### Code (C++)
```cpp
class Solution{
public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<int> dp(total + 1, 0);
        for(int i = n-1; i >= 0; i--) {
            for(int j = total; j >= 0; j--) {
                if(cost[i] <= j) {
                    int rem = j - cost[i] + (cost[i] * 9) / 10;
                    dp[j] = max(dp[j], 1 + dp[rem]);
                }
            }
        }
        return dp[total];
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.