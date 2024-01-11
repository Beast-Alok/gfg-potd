## 01. Longest subarray with sum divisible by K Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1)

Level : `Medium`

### My Approach
I solved this problem by prefix sum algorithm.
- We will iterate over array from end and calculate sum at each position.
- Now calculate remainder of sum at each position.
- If any of remainder mataches at any position then simply take out there distances and calculate the max distance.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N)
- **Auxiliary Space Complexity** : O(N)

### Code (C++)
```cpp
class Solution {
  public:
    int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int sum = 0;
	    unordered_map<int,int> suffix;
	    suffix[0] = n;
	    
	    int ans = 0;
	    
	    for(int i = n - 1; i > -1; i--){
	        sum = (sum + (arr[i] % k) + k) % k;
	        if(!suffix.count(sum))
	            suffix[sum] = i;
	        else
	            ans = max(ans, suffix[sum] - i);
	    }
	    
	    return ans;
	}
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.