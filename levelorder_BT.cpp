#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> levelOrder(node* root) {
    vector<vector<int>> result;

    if (root == NULL)
        return result;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int level = q.size();
        vector<int> visited;

        for (int i = 0; i < level; i++) {
            node* curr = q.front();
            q.pop();

            visited.push_back(curr->data);

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }

        result.push_back(visited);
    }

    return result;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);

    vector<vector<int>> result = levelOrder(root);

    for (auto level : result) {
        for (auto value : level) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}