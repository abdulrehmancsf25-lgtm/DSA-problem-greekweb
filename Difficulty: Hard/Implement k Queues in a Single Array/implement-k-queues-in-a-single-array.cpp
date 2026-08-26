class kQueues {
	
	public:
	int* arr ;
	int* front ;
	int*rear ;
	int* next ;
	int freespot ;
	kQueues(int n, int k) {
		// Initialize your data members
		arr = new int[n] ;
		next = new int[n] ;
		front = new int[k] ;
		rear = new int[k] ;
		
		memset(front, -1, k* sizeof(int)) ; // initialize with -1
		memset(rear, -1, k* sizeof(int)) ;
		for (int i = 0 ; i < n ; i++) { // next freespots for indices of arr
			next[i] = i + 1 ;
		}
		next[n - 1] = -1 ;
		freespot = 0 ; // first freespot is at index 0
	}
	
	void enqueue(int x, int i) {
		// enqueue element x into queue i
		if (isFull())
			return ;
		
		int index = freespot ; // index to push
		freespot = next[index] ; // update freespot
		if (front[i] == -1) { // first push
			front[i] = index ;
		}
		else {
			next[rear[i]] = index ;
		}
		next[index] = -1 ; // update next
		
		arr[index] = x ; // push
		
		rear[i] = index ; // updtae rear
		
	}
	
	int dequeue(int i) {
		// dequeue element from queue i
		if (isEmpty(i))
			return - 1 ;
		
		int index = front[i] ; // fetch front index
		front[i] = next[index] ; // updtae front
		next[index] = freespot ; // link index with next freespot
		freespot = index ; // update freespot to that index of front
		
		return arr[index] ;
	}
	
	bool isEmpty(int i) {
		return front[i] == -1 ;
	}
	
	bool isFull() {
		if (freespot == -1)
			return true ;
		return false ;
	}
};
