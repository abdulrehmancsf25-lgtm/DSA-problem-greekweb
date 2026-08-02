/* Link list Node
struct Node
{
	int data;
	struct Node* next;
	
	Node(int x) {
		data = x;
		next = NULL;
	}
	
};
*/
class Solution {
	public:
	bool isCircular(Node *head) {
		// code here
		Node* slow = head ;
		Node* fast = head->next ;
		while (fast != slow && fast != NULL) {
			fast = fast ->next ;
			if (fast != NULL)
				fast = fast -> next ;
			slow = slow -> next ;
			
		}
		if (fast == slow)
			return true ;
		return false ;
		
	}
};
