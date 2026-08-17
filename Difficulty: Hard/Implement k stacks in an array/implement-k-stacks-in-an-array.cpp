class kStacks {
	
	// main array to store elements
	int *arr;
	int *top ; // yop for all stacks
	int *next ; // point to next freespot or next element in stack
	// if not empty
	
	int freespot ; // points index for free spot
	public:
	kStacks(int n, int k) {
		// initialize data structures for k stacks
		freespot = 0 ;
		// initialize arr
		arr = new int[n] ;
		top = new int[k] ; // top array with size equal to no. of stacks
		
		next = new int[n] ; // next free spot for index of arr
		
		memset(top, -1, k* sizeof(int)) ; // initialize top array with -1
		
		for (int i = 0 ; i < n ; i++) // free spots for indexes of arr
			next[i] = i + 1 ;
		
		next[n - 1] = -1 ; // for last index element no free spot
	}
	
	void push(int x, int i) {
		// push element x into stack i
		// npo free spot available
		if (freespot == -1)
			return ;
		
		int index = freespot ; // index of free spot
		
		freespot = next[index] ; // next freespot for index of arr
		arr[index] = x ; // push element in arr
		next[index] = top[i ] ; // next index in stack
		top[i ] = index ; // update top of stack
	}
	
	int pop(int i) {
		// pop element from stack i
		// no element in stack
		if (top[i ] == -1)
			return - 1 ;
		
		int index = top[i] ; // i s stack no.
		top[i ] = next[index] ; // update top with next index in stack
		next[index] = freespot ; // update next
		freespot = index ; // index of arr now becomes freespot
		return arr[index] ; // return top element of stack
		
	}
};
