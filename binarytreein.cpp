#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node* insert(node* root, int key) {

    if (root == NULL) {
        root = new node(key);
        return root;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {

        node* curr = q.front();
        q.pop();

        // Check left child
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        else {
            curr->left = new node(key);
            return root;
        }

        // Check right child
        if (curr->right != NULL) {
            q.push(curr->right);
        }
        else {
            curr->right = new node(key);
            return root;
        }
    }

    return root;
}

void printLevelOrder(node* root) {

    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {

        node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main() {

    node* root = new node(20);

    root->left = new node(11);
    root->right = new node(9);

    root->left->left = new node(16);
    root->left->right = new node(17);

    root->right->left = new node(18);

    // Insert new node
    root = insert(root, 25);

    cout << "Level Order: ";
    printLevelOrder(root);

    return 0;
}