/* Structure of Linked List Node
class Node {
	public:
	int data;
	Node* next;
	Node* random;
	
	Node(int x) {
		data = x;
		next = random = nullptr;
	}
}; */

class Solution {
	public:
	Node* cloneLinkedList(Node* head) {
		Node* curr1 = head ;
		// creating newn nodes and point them b/w original ones
		while (curr1) {
			Node* temp = new Node(curr1-> data) ;
			temp -> next = curr1 -> next ;
			curr1 -> next = temp ;
			curr1 = temp -> next ;
		}
		// pointing random pointers of cloned nodes
		curr1 = head ;
		while (curr1) {
			Node* temp = curr1 -> random ;
			curr1 -> next -> random = temp ;
			if (temp)
				curr1 -> next -> random = temp -> next ;
			curr1 = curr1 -> next -> next ;
		}
		// extracting cloned nodes from original list
		curr1 = head ;
		Node* head2 = head -> next ;
		Node* curr2 = head2 ;
		
		while (curr1) {
			curr1 -> next = curr2 -> next ;
			curr1 = curr1 -> next ;
			curr2 -> next = curr1 ;
			if (curr1)
				curr2 -> next = curr1 -> next ;
			curr2 = curr2 -> next ;
			
		}
		return head2 ;
	}
};
