## 01. Shortest Prime Path Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/shortest-prime-path--141631/1)

Level : `Medium`

### My Approach
- The solution class uses a breadth-first search (BFS) approach to find the shortest path from `num1` to `num2` by altering only a single digit at a time. The solution involves generating all possible four-digit prime numbers and then using BFS to explore the possible paths between `num1` and `num2`.

**Sieve of Eratosthenes**:
The class initializes a boolean array p of size N+1 to mark whether a number is prime or not.
It uses the Sieve of Eratosthenes algorithm to mark all prime numbers up to N.
The buildSeive function is responsible for populating the p array with prime numbers.

**BFS**:
- The solve function initializes a queue to perform BFS, and a boolean array vis to keep track of visited numbers.
- It starts by pushing the initial number n1 into the queue with a distance of 0.
- It then enters a while loop that continues until the queue is not empty.
- Inside the loop, it dequeues a pair representing the current number and its distance from n1.
- If the current number is equal to num2, it updates the minimum distance if the current distance is smaller.
- It then explores all possible numbers that can be obtained by changing a single digit in the current number.
- For each digit in the current number, it tries replacing it with digits from 0 to 9 (excluding the current digit itself).
- If the resulting number is a four-digit prime and hasn't been visited before, it is marked as visited, and the pair {num, dist+1} is pushed into the queue.
- The loop continues until the queue is empty or the minimum distance is zero.

**Return Result**:
The function returns the minimum distance calculated during the BFS traversal.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(nlog(n))
- **Auxiliary Space Complexity** : O(n)

### Code (C++)
```cpp
#define N 10002
class Solution{
public:
    bool p[N];
    void buildSeive(){
        for(int i=2; i<=N; i++)
            p[i] = true;

        for(int i=2; i*i<=N; i++)
            if(p[i]){
                for(int j=i*i; j<=N; j+=i)
                    p[j] = false;
            }
    }

    int solve(int n1,int n2){   
        // n1 --> n2
        queue<pair<int,int>> q; // {Pnum, dist}
        bool vis[N] = {0};

        q.push({n1,0});
        vis[n1] = true;
        int minDist = 1e8;
        buildSeive();

        while(!q.empty()){
            auto it = q.front();
            int n = it.first;
            int dist = it.second;
            q.pop();

            if(n==n2){
                minDist = min(minDist, dist);
                if(minDist==0)
                    break;
            }

            for(int d=1; d<=n; d*=10){
                int dig = (n/d)%10;
                for(int i=0; i<=9; i++){
                    if((i==0 && d==4) || i==dig)
                        continue;
                    int num = n - dig*d + i*d;
                    if(num>=1000 && p[num] && !vis[num]){
                        vis[num] = true;
                        q.push({num, dist+1});
                    }
                }
            }
        }
        return minDist;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.