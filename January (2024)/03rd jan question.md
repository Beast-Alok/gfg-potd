## 01. Smallest window containing 0, 1 and 2 Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1)

Level : `Easy`

### My Approach
I solved this problem by two pointer algorithm.

- First create a vector `f` of size of `3` elements initialized with `0`.
- Create a left pointer `l` and right pointer `r` set them to zero, also create variable `len` to store the size of smallest substring and variable `res` to check whether we got our substring or not.
- Now iterate over string `S` move pointer `r` toward right and increase the frequency of respective number in vector f.
  Note : f[0] is for '0', f[1] is for '1', f[2] is for '2'.
- Once we got substring and update `res` is equal to 1 then move pointer `l` toward right untill our condition is again false means `res` is equal to zero.
- Also when `res` is equal to one then also consider to take that min size of substring.
- At last return `len` as `-1` is len is unchanged or return `len`.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(length(S)), where S is the input string.
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution {
  public:
    int smallestSubstring(string S) {
        vector<int> f(3,0);
        int l=0,r=0;
        int len = 1e8;
        bool res = 0;

        while(r < S.size() || l < r){
            if (!res && r < S.size())
            {
                ++f[S[r++] - 48];
                if(f[0] && f[1] && f[2]){
                    res = 1;
                }else{
                    res = 0;
                }
            }
            else if (l<r)
            {
                --f[S[l++] - 48];
                if(f[0] && f[1] && f[2]){
                    res = 1;
                }else{
                    res = 0;
                }
            }
            if (res)
            {
                len = min(len, r-l);
            }
        }
        return len == 1e8 ? -1 : len;
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.