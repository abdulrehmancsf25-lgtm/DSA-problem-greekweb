class Node {
  public:
    int data;
    Node* prev;
    Node* next;
    Node(int x): data(x) , prev(NULL) , next(NULL) {
       
    }
};

class myDeque {
   Node* front ;
   Node* rear ;
  public:
    myDeque() {
        // Initialize your data members
        front = NULL ;
        rear = NULL ;
    }

    void insertFront(int x) {
        // Insert element at the front
         Node* temp = new Node(x) ;
        if(!front && !rear){
            front = temp ;
            rear = front ;
        }
        else{
            temp -> next = front ;
            front -> prev = temp ;
            front = temp ;
        }
    }

    void insertRear(int x) {
        // Insert element at the rear
        Node* temp = new Node(x) ;
         if(!front && !rear){
            front = temp ;
            rear = front ;
        }
        else{
             rear -> next = temp ;
             temp -> prev = rear ;
             rear = temp ;
        }
    }

    void deleteFront() {
        // Delete element from the front
        if(!front)
         return;
        
        if(front == rear){
             front = NULL ;
             rear = NULL ;
             return ;
        }
        Node* temp = front ;
        front = front -> next ;
        front -> prev = NULL ;
        delete temp ;
    }

    void deleteRear() {
        // Delete element from the rear
        if(!rear)
         return ;
        
        Node* temp = rear ;
        rear = rear -> prev ;
        if(rear)
          rear -> next = NULL ;
        else
           front = NULL ;
        delete temp ;
    }

    int getFront() {
        // Return front element (-1 if empty)
        if(front == NULL)
         return -1 ;
        return front -> data ;
    }

    int getRear() {
        // Return rear element (-1 if empty)
        if(rear == NULL)
         return -1 ;
        return rear -> data ;
    }
};
