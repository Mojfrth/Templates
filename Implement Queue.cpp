#include <iostream>
using namespace std;

class Queue {
    int front, rear, capacity;
    int* queue;

public:
    Queue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    void enqueue(int value) {
        if (rear == capacity - 1)
            return;
        if (front == -1)
            front = 0;
        queue[++rear] = value;
    }

    int dequeue() {
        if (front == -1 || front > rear)
            return -1;
        return queue[front++];
    }

    int peek() {
        if (front == -1 || front > rear)
            return -1;
        return queue[front];
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    ~Queue() {
        delete[] queue;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.enqueue(40);
    cout << "Front element: " << q.peek() << endl;

    return 0;
}
