/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/
Node* reverseLst(Node* &head){
    // base case
    if(head == NULL || head->next == NULL)
    return head ;
    
    // reverse remaining list except first node(recursion calls)
    Node* smallHead = reverseLst(head ->next) ;
    head ->next->next = head ;
    head -> next = NULL ;
    
    return smallHead ;
}


class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        return reverseLst(head) ;
    }
};