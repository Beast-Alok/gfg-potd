## 01. Techfest and the Queue Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/techfest-and-the-queue1044/1)

Level : `Medium`

### My Approach
I solved this problem using one pointer only.

- Iterate over a range of number given (from `a` to `b`)
- Now calculate all divisor that number and also count number of time it may get divide
- Now calculate for all the number from `a` to `b`.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O( b*log(b) )
- **Auxiliary Space Complexity** : O( b*log(b) )

### Code (C++)
```cpp
class Solution {
  public:
    int primePowers(int n)
    {
        int cnt = 0;
        for(int i = 2; i <= sqrt(n); i++)
        {
            while(n % i == 0)
            {
                cnt++;
                n = n / i;
            }
        }
        if(n > 1)
            cnt++;
        
        return cnt;
    }
    
    int sumOfPowers(int a, int b)
    {
        int cnt = 0;
        for(int i = a; i <= b; i++)
            cnt += primePowers(i);
        return cnt;
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.