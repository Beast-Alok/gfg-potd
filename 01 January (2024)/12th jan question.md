## 01. Reverse First K elements of Queue Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/reverse-first-k-elements-of-queue/1)

Level : `Easy`

### My Approach
I solved this problem by using stack
example : 
Q = [1, 2, 3, 4, 5]
S = []
- First I removed first `k` element of queue and pushed them into stack.
Q = [4, 5]
S = [1, 2, 3]
- Now again pop them from stack and push them again in the queue back.
Q = [4, 5, 3, 2, 1]
S = []
- Now remove remaining `n-k` element of queue and push them into stack but with each removal push them back into queue at the same time.
Q = [3, 2, 1, 4, 5]
S = []

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N)
- **Auxiliary Space Complexity** : O(K)

### Code (C++)
```cpp
class Solution {
  public:
    queue<int> modifyQueue(queue<int> q, int k) {
        stack <int> S;
        int n = q.size();
        for(int i = 0; i < k; i++){
            S.push(q.front());
            q.pop();
        }
        while(!S.empty()){
            q.push(S.top());
            S.pop();
        }
        for(int i =0 ; i < n-k; i++){
            S.push(q.front());
            q.pop();
            q.push(S.top());
            S.pop();
        }
        return q;
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.