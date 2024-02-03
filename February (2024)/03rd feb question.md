## 01. Decimal Equivalent of Binary Linked List Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1)

Level : `Easy`

### My Approach

- The `solve` function is a recursive helper function that traverses the linked list, updating the result by multiplying it by 2 and adding the binary digit at the current node. The modulo operation ensures that the result doesn't exceed the given constant MOD (1000000007).

- The `decimalValue` function is a public function that initializes the result to 0 and then calls the `solve` function to calculate the final decimal value of the binary linked list.

- In the `main` function, a linked list is created based on user input, and the `decimalValue` function is called for each test case, printing the result.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n)
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution{
  public:
    void solve(Node *head, long long unsigned int &result){
        if(head == NULL){
            return;
        }
        result = (result*2 + head->data) % 1000000007;
        solve(head->next, result);
    }   
    long long unsigned int decimalValue(Node *head)
    {
        long long unsigned int result = 0;
        solve(head, result);
        return result;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.