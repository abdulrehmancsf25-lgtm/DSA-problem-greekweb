/* Node is defined as
class Node {
	public:
	int data;
	Node* next;
	
	Node(int x) {
		data = x;
		next = nullptr;
	}
};
*/
class Solution {
	public:
	Node* segregate(Node* head) {
	    // Create dummy Nodes 
		Node* zero = new Node(0) ;
		Node* one = new Node(0) ;
		Node* two = new Node(0) ;
		Node* zcurr = zero ;
		Node* ocurr = one ;
		Node* tcurr = two ;
		// traverse main linked list
		while (head) {
			int val = head -> data ;
			if (val == 0) {
				zcurr -> next = head ;
				zcurr = head ;
			}
			else if (val == 1) {
				ocurr -> next = head ;
				ocurr = head ;
			}
			else {
				tcurr -> next = head ;
				tcurr = head ;
			}
			head = head -> next ;
		}
		// make sure to make last node -> next = NULL 
		tcurr -> next = NULL ;
		ocurr -> next = two -> next ;
		delete two ;
		zcurr -> next = one -> next ;
		delete one ;
		// new linked list head 
		return zero -> next ;
		
	}
};
