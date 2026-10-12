#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push() {
    int x;
    cout << "Enter element to push: ";
    cin >> x;
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        cout << "Underflow\n";
        exit(0);
    }
    int x = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return x;
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Push\n2. Pop\n3. Display\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            cout << "Popped element: " << pop() << "\n";
            break;
        case 3:
            display();
            break;
        default:
            cout << "Invalid choice\n";
            exit(0);
        }
    } while (choice <= 3);

    return 0;
}