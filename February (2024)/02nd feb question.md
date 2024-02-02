## 01. Implement Atoi Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/implement-atoi/1)

Level : `Medium`

### My Approach

- **Initialization**: Initialize `result` to 0, which will be used to accumulate the converted integer, and `sign` to 1, indicating a positive number by default.

- **Handling Sign**: Check if the first character of the string is a negative sign ('-'). If yes, set `sign` to -1 and skip the negative `sign` in the string using `s.substr(1)`.

- **Iterating through the String**: Use a range-based for loop to iterate through each character `c` in the string s.

- **Checking for Valid Digit**: Inside the loop, check if the current character `c` is a valid digit using `isdigit(c)`. If it's not a digit, return -1, indicating an invalid input.

- **Updating Result**: Update the result by multiplying the current result by 10 and adding the numeric value of the current digit `(c - '0')`. This effectively shifts the current result to the left by one digit and adds the new digit.

- **Final Result with Sign**: After the loop, return the final result multiplied by the sign (`result * sign`). This ensures that the result is negative if the original string had a negative sign at the beginning.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O( |s| )
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution{
  public:
    int atoi(string s) {
        int result = 0;
        int sign = 1;

        if (s[0] == '-') {
            sign = -1;
            s = s.substr(1);
        }

        for (char c : s) {
            if (!isdigit(c))
                return -1;

            result = result * 10 + (c - '0');
        }
        return result * sign;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.