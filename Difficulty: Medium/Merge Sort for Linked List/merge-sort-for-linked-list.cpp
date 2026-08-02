/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  private:
 
   Node* merge(Node* &l1 , Node* l2){
      if( !l1 && l2)
       return l2 ;
      if(!l2 && l1)
      return l1;
        Node* curr = l1 ;
        Node* temp = NULL ;
     while(curr -> next && l2){
        temp = l2 -> next ;
        if(l2 -> data >= curr-> data && l2 -> data <= curr->next->data){
        l2 -> next = curr -> next ;
        curr -> next = l2 ;
        l2 = temp ;
        }
        else
          curr = curr -> next ;
     }
    if(l2)
      curr -> next = l2 ;
    return l1 ;
       
   }
  public:
    Node* mergeSort(Node* head) {
        // code here
        if(head == NULL || head -> next == NULL)
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
        Node* left = mergeSort(head );
        // sort right part 
        Node* right = mergeSort(temp ) ;
        
        if(left -> data < right -> data)
       head = merge(left , right) ;
       else
         head = merge(right , left) ;
       return head ;
    }
};