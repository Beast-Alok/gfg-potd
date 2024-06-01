#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

//gfg solution from here
class Solution
{
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

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		Node *head = NULL;
		Node *temp = head;
		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
		head = ob.insertionSort(head);
		printList(head);
		cout << "\n";
	}
	return 0;
}
// code written by alok kumar raaghuwanshi 