/* Structure of linked list Node
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
  Node* reverseList(Node* head ){
      if(head == NULL || head -> next == NULL)
      return head ;
    Node* smallHead = reverseList(head -> next ) ;
    head -> next -> next =  head ;
    head -> next = NULL ;
    return smallHead ;
      
  }
    Node* addOne(Node* head) {
        // code here
        Node* curr = reverseList(head) ;
        Node* newHead = curr ;
        Node* prev = NULL ;
        int carry = 0 , ans = 0 ;
        
         ans = curr -> data + 1 ;
         if (ans < 10 ){
         curr -> data = ans ;
         return reverseList(curr) ;
         }
        
        while(ans >= 10 || curr){
            carry = ans / 10 ;
            ans %= 10 ;
            curr -> data = ans ;
            ans = carry ;
            
            prev = curr ;
            curr = curr -> next ;
            if(curr)
             ans += curr -> data ;
        }
        if(carry){
            Node* temp = new Node(carry) ;
            prev -> next = temp ;
        }
    
    return reverseList(newHead) ;
    }
};