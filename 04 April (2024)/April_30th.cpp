//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverseList(Node* head) {
        Node* current = head;
        Node* previous = NULL;
        
        while(current != NULL) {
            Node* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        
        return previous;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        if(num1 == NULL)
            return num2;
        if(num2 == NULL)
            return num1;
        
        // Reverse both input lists
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        
        // Initialize a dummy node to build the result list
        Node* dummy = new Node(-1);
        Node* current = dummy;
        
        int carry = 0;
        // Iterate through both lists or carry is still present
        while(num1 != NULL || num2 != NULL || carry == 1) {
            int sum = carry;
            // Add values of both nodes if available
            if(num1 != NULL) {
                sum += num1->data;
                num1 = num1->next;
            }
            if(num2 != NULL) {
                sum += num2->data;
                num2 = num2->next;
            }
            
            // Calculate the value and carry for the current position
            int value = sum % 10;
            carry = sum / 10;
            
            // Append the new node with calculated value to the result list
            current->next = new Node(value);
            current = current->next;
        }
        
        // Reverse the result list and remove leading zeros if any
        dummy->next = reverseList(dummy->next);
        current = dummy->next;
        while(current != NULL && current->data == 0)
            current = current->next;
        
        // If the result list is empty, return a single node with value 0
        return current == NULL ? new Node(0) : current;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
