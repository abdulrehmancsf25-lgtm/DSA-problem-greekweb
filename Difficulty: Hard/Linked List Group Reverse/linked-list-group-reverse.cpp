/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head == nullptr)
        return head  ;
        
        Node* prev = nullptr;
        Node* curr = head ;
        Node* forward = nullptr ;
        
        int i = 1 ;
        while( i <= k && curr != nullptr){
            forward = curr->next ;
            curr ->next = prev ;
            prev = curr ;
            curr = forward ;
            i++ ;
        }
        head ->next  = reverseKGroup(curr , k) ;
        return prev ;
    }
};