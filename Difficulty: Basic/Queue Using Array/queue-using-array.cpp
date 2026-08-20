class myQueue {
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    myQueue(int n) {
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear = 0;
        count = 0;
    }

    ~myQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void enqueue(int x) {
        if (isFull()) return;
        arr[rear] = x;
        rear = (rear + 1) % capacity;
        count++;
    }

    void dequeue() {
        if (isEmpty()) return;
        front = (front + 1) % capacity;
        count--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        // Handle wrap-around index for rear
        int lastIndex = (rear - 1 + capacity) % capacity;
        return arr[lastIndex];
    }
};