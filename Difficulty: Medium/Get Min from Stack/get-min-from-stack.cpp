class SpecialStack {
  public:
      vector<int> st ;
      int mini = INT_MAX ;
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        // Add an element to the top of Stack
        mini = min(mini , x) ;
        st.push_back(x) ;
        st.push_back(mini) ;
    }

    void pop() {
        // Remove the top element from the Stack
        if(st.size()) {
        st.pop_back() ;
        st.pop_back() ;
        if(st.size())
          mini = st.back() ;
        }
        if(!st.size())
          mini = INT_MAX ;
    }

    int peek() {
        // Returns top element of the Stack
        if(st.size()){
            int temp = st.back() ;
            st.pop_back();
            int p = st.back() ;
            st.push_back(temp) ;
            return p ;
        }
        else
           return -1 ;
    }

    bool isEmpty() {
        // Check if stack is empty
        if(st.size())
           return false ;
          else 
          return true ;
    }

    int getMin() {
        // Finds minimum element of Stack
        if(st.size())
        return st.back() ;
        
        return -1 ;
        
    }
};