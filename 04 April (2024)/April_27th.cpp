//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *getMid(struct Node *head) {
        struct Node *slow = head;
        struct Node *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    struct Node *merge(struct Node *left, struct Node *right) {
         // If any of the lists is empty, return the other one.
        if (!left) return right;
        if (!right) return left;
        
        // Choose the smaller value node among left and right
        // and recursively merge the remaining lists.
        if (left->data < right->data) {
            left->next = merge(left->next, right);
            left->next->prev = left;
            left->prev = NULL;
            return left;
        } else {
            right->next = merge(left, right->next);
            right->next->prev = right;
            right->prev = NULL;
            return right;
        }
    }


    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if (head == NULL || head->next == NULL)
            return head;
        struct Node *mid = getMid(head);
        struct Node *nextToMid = mid->next;
        mid->next = NULL;
        nextToMid->prev = NULL;
        return merge(sortDoubly(head), sortDoubly(nextToMid));
        
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends
