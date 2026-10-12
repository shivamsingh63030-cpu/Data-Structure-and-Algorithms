#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

queue<Node*> q;

Node* insert(Node* root, int value) {
    Node* newNode = new Node(value);

    if (root == NULL) {
        q.push(newNode);
        return newNode;
    }

    Node* curr = q.front();

    if (curr->left == NULL)
        curr->left = newNode;
    else if (curr->right == NULL) {
        curr->right = newNode;
        q.pop();
    }

    q.push(newNode);
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);

    return 0;
}