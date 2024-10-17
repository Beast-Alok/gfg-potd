//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
         vector<Node *>ans;
         Node *temp1=new Node(-1);
         Node *val1=temp1;
         Node *temp2=new Node(-1);
         Node *val2=temp2;
        Node *first=head,*second=head->next;
        
        while(first!=NULL){
            temp1->next=new Node(first->data);
            temp1=temp1->next;
            if(first->next)first=first->next->next;
            else first=first->next;
        }
        ans.push_back(val1->next);
        
        
         while(second!=NULL){
            temp2->next=new Node(second->data);
            temp2=temp2->next;
            if(second->next)second=second->next->next;
            else second=second->next;
        }
        ans.push_back(val2->next);
       
        return ans;
        
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends
