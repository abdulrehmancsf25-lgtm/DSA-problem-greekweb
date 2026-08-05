/*
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
    Node *moveToFront(Node *head) {
        // code here
        if (!head -> next)
        return head ;
        Node* prev = NULL ;
        Node* curr = head ;
        while(curr -> next){
            prev = curr ;
            curr = curr -> next ;
        }
        prev -> next = NULL ;
        curr -> next = head ;
        return curr ;
    }
};