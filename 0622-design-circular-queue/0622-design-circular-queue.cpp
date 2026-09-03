class MyCircularQueue {
public:
    vector<int> arr;
    int front;int rear;int count;int size;

    MyCircularQueue(int k) {
        arr.resize(k);
        front = 0;
        rear = 0;
        count = 0;
        size = k;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;

        arr[rear] = value;
        rear = (rear + 1) % size;
        count++;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % size;
        count--;

        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;

        return arr[front];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;

        return arr[(rear - 1 + size) % size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};