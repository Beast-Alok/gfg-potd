## 01. Sequence of Sequence Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1)

Level : `Medium`

### My Approach
I solved this problem by recursive approach
- Each number in the sequence should follow these rules:
  - If the number is not selected, it is decreased by one.
  - If the number is selected, it is passed half to the previous number.

[NOTE] : The provided code should solve the problem, but keep in mind that the recursive solution might not be efficient for large values of m and n. For better performance, you might want to consider dynamic programming or memoization techniques to avoid redundant calculations.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(m*n)
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution{
public:
    int solve(int i, int m){
        //base contition 
        //if get n numbers
        if(i==0)
            return 1;
            
        //if before getting n numbers our sequence reached 0
        if(m==0)
            return 0;
            
        // if we take the element and passing it half to previous element
        int take=solve(i-1,m/2);
        
        // if we are  not taking the element and decreasing it by one
        int notTake=solve(i,m-1);
        
        //return count of both the sequences 
        return take+notTake;
    }
    int numberSequence(int m, int n){
        return solve(n,m);
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.