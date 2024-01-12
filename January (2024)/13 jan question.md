## 01. Insertion Sort for Singly Linked List Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/1)

Level : `Medium`

### My Approach
I solved this problem by using vector

- Firstly moved all the element of the linked list in vector `v` and sorted the list.
- Now again insert the elements from the vector to linked list.
- Return linked list again.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N^2)
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution {
  public:
    Node* insertionSort(struct Node* head_ref)
    {
        Node *cur, *mnew;
        vector<int> v;
        while (head_ref != NULL)
        {
            v.push_back(head_ref->data);
            head_ref = head_ref->next;
        }
        sort(v.begin(),v.end());
        for(const auto ele : v){
            mnew = new Node(ele);
            if(head_ref == NULL){
                head_ref = mnew;
                cur = head_ref;
            }else{
                cur ->next = mnew;
                cur = cur->next;
            }
        }
        return head_ref;
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.