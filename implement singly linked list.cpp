#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist {
    Node *head;

  public:
    Linkedlist() {
        head = NULL;
    }

    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
    }

    void print() {
        Node *temp = head;
        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    Linkedlist list;
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);

    cout << "Elements of the list are: ";
    list.print();
    cout << endl;

    return 0;
}
