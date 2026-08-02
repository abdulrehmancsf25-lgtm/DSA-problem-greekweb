/* Structure of linked list Node
class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        Node* curr = head ;
        Node* prev = NULL ;
        unordered_set<int> visitedVal ;
        while(curr){
             if(visitedVal.count(curr -> data) ){
                prev -> next = curr -> next ;
                Node* temp = curr ;
                curr = prev -> next ;
                delete temp ;
             }
            else{
            visitedVal.insert(curr -> data) ;
            prev = curr ;
            curr = curr ->next ;
            }
        }
    return head ;
    }
};