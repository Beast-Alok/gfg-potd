## 01. Split Array Largest Sum Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1)

Level : `Hard`

### My Approach
I solved this problem using binary search algorithm to find maximum subarray with minimum sum posible.

- Here in the code `low` represents the max sum of minimum subarray and `high` represents the max sum of maximum subarray.
- We have to find minimum sum with maximum subarray.
- Also number of subarray is also defined so after dividing whole array into `k` subarray which subarray have most element with less sum this is only we have to find.
- Here we get assumption of `mid` value again and again by binary search algorithm and we check for every `mid` value that is possible minimum sum or not.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N*log(sum(arr)))
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution {
  public:
    bool check(int arr[], int mid, int k, int n){
        int cut = 1, sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum > mid){
                sum = arr[i];
                cut++;
            }
        }
        return cut <= k;
    }
    
    int splitArray(int arr[] ,int N, int K) {
        int low = 0, high = 0, ans = 0;
        for(int i=0; i < N; i++){
            high += arr[i], low = max(low,arr[i]);
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(check(arr,mid,K,N)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.