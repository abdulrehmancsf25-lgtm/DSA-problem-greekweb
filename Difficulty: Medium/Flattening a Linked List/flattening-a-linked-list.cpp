/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  private:
    Node* merge(Node* l1 , Node* l2) {
        Node* dummy = new Node(0) ;
        Node* curr   =  dummy ;
        while(l1 && l2 ){
            if(l1 -> data < l2 -> data){
             curr -> bottom = l1 ;
             l1 = l1 -> bottom ;
             
            }
            else{
                curr -> bottom = l2 ;
                l2 = l2 -> bottom ;
                
            }
            curr = curr -> bottom ;
        }
        // for l1 
        while(l1){
             curr -> bottom = l1 ;
             l1 = l1 -> bottom ;
              curr = curr -> bottom ;
        }
         // for l2
        while(l2){
             curr -> bottom = l2 ;
             l2 = l2 -> bottom ;
              curr = curr -> bottom ;
        }
       return dummy -> bottom ;
    }
  public:
    Node* flatten(Node* head) {
        // code here
        if (!head || !head -> next)
        return head ;
        
        Node* slow = head ;
        Node* fast = head -> next ;
        
        while(fast && fast -> next ){
            fast = fast -> next ;
            if(fast)
             fast = fast -> next ;
            slow = slow -> next ;
        }
        
         Node* temp = slow -> next ;
        slow -> next = NULL ;
       
        // sort left part 
        Node* left = flatten(head );
        // sort right part 
        Node* right =flatten(temp ) ;
        
         head = merge(left , right) ;
         return head ;
       
    }
};