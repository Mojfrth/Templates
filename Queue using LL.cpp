#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Queue {
    Node *front, *rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() { return !front; }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear) rear->next = newNode;
        else front = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (isEmpty()) return;
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    int peek() {
        if (isEmpty()) return -1;
        return front->data;
    }
