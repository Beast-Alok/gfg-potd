## 01. Fractional Knapsack Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)

Level : `Medium`

### My Approach

**Data Structure**:
- The Item structure is defined to represent each item with its value and weight.

**Sorting by Value-to-Weight Ratio**:
- The idea behind Fractional Knapsack is to choose items with the maximum value-to-weight ratio first.
- The fractionalKnapsack function creates a vector v of pairs, where each pair stores the value-to-weight ratio and the weight of an item.
- This vector is then sorted in non-decreasing order of value-to-weight ratio.

**Greedy Selection**:
- Starting with the item with the highest value-to-weight ratio (since it is at the end of the sorted vector), the algorithm iterates through the sorted vector.
- For each item, it calculates the amount of the item that can be taken (either the entire item or a fraction of it) and adds the corresponding value to the total value in the knapsack.
- This process continues until the knapsack is full (i.e., w becomes 0) or all items are considered.

**Return Result**:
- The total value of the items selected is returned as the result.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(nlog(n))
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
#define N 10002
class Solution{
public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,double>>v;
        for(int i=0;i<n;i++){
            v.push_back({double(arr[i].value)/double(arr[i].weight),double(arr[i].weight)});
        }
        sort(v.begin(), v.end());
        double w= double(W);
        double ans=0;
        int i=n-1;
        while(w>0 && i>=0){
            double x=min(w, v[i].second);
            w-=x;
            ans+=x*v[i].first;
            i--;
        }
        return ans;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.