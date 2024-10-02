#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if (head != nullptr) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    void insertAtTail(int data) {
        if (head == nullptr) {
            insertAtHead(data);
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int data) {
        if (head == nullptr) return;

        Node* temp = head;

        if (temp->data == data) {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != data) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp->next != nullptr) temp->next->prev = temp->prev;
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        delete temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtHead(5);
    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.printList();

    dll.deleteNode(10);
    dll.printList();

    dll.insertAtTail(25);
    dll.printList();

    return 0;
}
