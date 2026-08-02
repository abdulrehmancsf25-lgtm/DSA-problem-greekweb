/* The structure of linked list is the following
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x) {
		data = x;
		next = NULL;
	}
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
	public:
	pair<Node *, Node *> splitList(struct Node *head) {
		// code here
		Node* slow = head ;
		Node* fast = slow -> next ;
		while (fast && fast ->next != head) {
			fast = fast -> next ;
			if (fast -> next != head)
				fast = fast -> next ;
			slow = slow -> next ;
		}
		fast -> next = slow -> next ;
		Node* temp = slow -> next ;
		slow -> next = head ;
		pair <Node*, Node*> ans = {head, temp} ;
		
		return ans ;
		
	}
};
