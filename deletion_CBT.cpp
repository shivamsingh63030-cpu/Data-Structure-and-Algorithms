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

Node* deleteNode(Node* root, int value) {
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == value) {
            delete root;
            return NULL;
        }
        return root;
    }

    queue<Node*> q;
    q.push(root);

    Node* target = NULL;
    Node* lastNode = NULL;
    Node* parent = NULL;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->data == value)
            target = curr;

        if (curr->left != NULL) {
            parent = curr;
            lastNode = curr->left;
            q.push(curr->left);
        }

        if (curr->right != NULL) {
            parent = curr;
            lastNode = curr->right;
            q.push(curr->right);
        }
    }

    if (target == NULL)
        return root;

    target->data = lastNode->data;

    if (parent->right == lastNode)
        parent->right = NULL;
    else
        parent->left = NULL;

    delete lastNode;

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
    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    cout << "Before Deletion: ";
    levelOrderTraversal(root);

    root = deleteNode(root, 30);

    cout << "\nAfter Deletion: ";
    levelOrderTraversal(root);

    return 0;
}