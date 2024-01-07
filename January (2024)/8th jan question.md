## 01. Merge 2 sorted linked list in reverse order Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1)

Level : `Medium`

### My Approach
I solved this problem by checking data of both `node1` and `node2` and appending it to starting of `node3`;

- While loop till data of both `node1` and `node2` are not equal to `NULL`.
- Now check data of both node.
- If data of `node1` is smaller so insert it in `node3` else insert `node2`.
- If data of one node is remaining but other is empty then insert all the remaining data of that node into `node3` without comparision.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N+M)
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution {
  public:
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node* node3 = NULL, *temp3 = NULL;
        while(node1 != NULL || node2 != NULL){
            if (node1 != NULL && node2 == NULL)
            {
                if(node3 == NULL){
                    node3 = temp3 = newNode(node1->data);
                    node1 = node1->next;
                }else{
                    temp3 = newNode(node1->data);
                    node1 = node1->next;
                    temp3->next = node3;
                    node3 = temp3;
                }
            }
            else if (node2 != NULL && node1 == NULL)
            {
                if(node3 == NULL){
                    node3 = temp3 = newNode(node2->data);
                    node2 = node2->next;
                }else{
                    temp3 = newNode(node2->data);
                    node2 = node2->next;
                    temp3->next = node3;
                    node3 = temp3;
                }
            }
            else if(node1->data <= node2->data){
                if(node3 == NULL){
                    node3 = temp3 = newNode(node1->data);
                    node1 = node1->next;
                }else{
                    temp3 = newNode(node1->data);
                    node1 = node1->next;
                    temp3->next = node3;
                    node3 = temp3;
                }
            }
            else if (node1->data > node2->data){
                if(node3 == NULL){
                    node3 = temp3 = newNode(node2->data);
                    node2 = node2->next;
                }else{
                    temp3 = newNode(node2->data);
                    node2 = node2->next;
                    temp3->next = node3;
                    node3 = temp3;
                }
            }
        }
        return node3;
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.